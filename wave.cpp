#include <fmt/ranges.h>
#include <algorithm>
#include <array>
#include <numeric>
#include <ranges>
#include <vector>
#include <cmath>
#include <iostream>

#include <chrono>
#include <random>


#include "graphics_manager.hpp"

namespace stdv = std::ranges::views;
namespace rng = std::ranges;
template<typename T> struct Point
{
    T x,y,z,d;
    Point normalize() const
    {
        using std::sqrt;
        const auto scale = 1/sqrt(x*x + y*y + z*z);
        return {x*scale, y*scale, z*scale};
    }
};

template<typename T>
std::vector<Point<T>> generateRandomPoints(std::size_t n)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<T> dis(-10.0, 10.0);
    std::uniform_real_distribution<T> dis2(-100, 100);
    std::vector<Point<T>> points(n);

    auto generatePoint = [&]() -> Point<T> {
        return {dis2(gen), dis2(gen), dis(gen), 0};
    };

    std::generate(points.begin(), points.end(), generatePoint);

    return points;
}




template <typename T> struct fmt::formatter<Point<T>> {
  // Presentation format: 'f' - fixed, 'e' - exponential.
  char presentation = 'f';

  // Parses format specifications of the form ['f' | 'e'].
  constexpr auto parse(format_parse_context& ctx) -> format_parse_context::iterator {
    // [ctx.begin(), ctx.end()) is a character range that contains a part of
    // the format string starting from the format specifications to be parsed,
    // e.g. in
    //
    //   fmt::format("{:f} - point of interest", point{1, 2});
    //
    // the range will contain "f} - point of interest". The formatter should
    // parse specifiers until '}' or the end of the range. In this example
    // the formatter should parse the 'f' specifier and return an iterator
    // pointing to '}'.

    // Please also note that this character range may be empty, in case of
    // the "{}" format string, so therefore you should check ctx.begin()
    // for equality with ctx.end().

    // Parse the presentation format and store it in the formatter:
    auto it = ctx.begin(), end = ctx.end();
    if (it != end && (*it == 'f' || *it == 'e')) presentation = *it++;

    // Check if reached the end of the range:
    if (it != end && *it != '}') throw_format_error("invalid format");

    // Return an iterator past the end of the parsed range:
    return it;
  }

  // Formats the point p using the parsed format specification (presentation)
  // stored in this formatter.
  auto format(const Point<T>& p, format_context& ctx) const -> format_context::iterator {
    // ctx.out() is an output iterator to write to.
    return presentation == 'f'
              ? fmt::format_to(ctx.out(), "({:.1f}, {:.1f}, {:.1f})", p.x, p.y, p.z)
              : fmt::format_to(ctx.out(), "({:.1e}, {:.1e}, {:.1e})", p.x, p.y, p.z);
  }
};

int main() 
{ 
    //printing points
    std::vector<Point<float>> a = { {1.0f, 2.0f, 3.0f}, {4.0f, 5.0f, 6.0f}, {7.0f, 8.0f, 9.0f}, {10.0f, 11.0f, 12.0f}, {13.0f, 14.0f, 15.0f}, {16.0f, 17.0f, 18.0f} , {0.0f, 0.0f, 0.0f},  {0.0f, 1.0f, 0.0f}, {0.0f, 2.0f, 0.0f},  {0.0f, 4.0f, 0.0f} };    
    fmt::print("{}\n", a);

    std::vector<Point<float>> random_points = generateRandomPoints<float>(10000);


    float simTime = 0;
    float A1 = 0;
    float A2 = 2;
    float B1 = 0;
    float B2 = 1;
    float omega = 1;
    float c = 10;
    auto wave_equation = [&simTime,omega,c, A1, A2, B1, B2](Point<float> i) -> Point<float> {
        float u = (B1*std::cos(omega*i.x/c) + B2*std::sin(omega*i.x/c)) * (A1*std::cos(omega*simTime) + A2*std::sin(omega*simTime));
        return {i.x + u, i.y,i.z, u/((A1+A2)*(B1+B2))};
        };

    auto u = [&simTime,omega, c, A1, A2, B1, B2](Point<float> i) -> Point<float> {
        float u = std::sin(omega*i.y/c)  * std::sin(omega*i.x/c) * (A1*std::cos(omega*simTime) + A2*std::sin(omega*simTime));
        return {i.x , i.y,i.z + u, u/(A1+A2)};
        };
    auto moved_points = random_points | stdv::transform(u);

    
    double targetFrameTime = 0.1;
    double gameDeltaTime;
    double realDeltaTime;
    double simDeltaTime;
    GraphicsManager gm(1000, 800, "my window");
    gm.init();

    auto time_stamp = std::chrono::high_resolution_clock::now();
    while(!gm.shoulCloseWindow()){
        // input
        // -----
        gm.processInput();
        realDeltaTime = std::chrono::duration<float>(std::chrono::high_resolution_clock::now() - time_stamp).count();
        time_stamp = std::chrono::high_resolution_clock::now();
        simDeltaTime = realDeltaTime * gm.gameTimeFactor;
        simTime += simDeltaTime;

      // Render outputs
       // render
        // ------
        gm.render(moved_points);


        if (std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - time_stamp).count() < targetFrameTime - 0.01)
        {
            sleep(targetFrameTime - std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - time_stamp).count());
        }
        
    }

}