#include <iostream>
#include <cstdlib>

#include <array>
#include "math/vec2.hpp"
#include "math/vec3.hpp"
#include "math/horner.hpp"

void test_surface(void);

int main(void)
{

  std::array<vec2, 2> ctrl_points;

  ctrl_points[0] = vec2(1.0f, 0.0f);
  ctrl_points[1] = vec2(1.0f, 1.0f);

  vec2 point = horner<vec2, float, 2>(ctrl_points.data(), 0.5f);
  //vec2 v(0.0f,0.0f);

  std::cout << "(" << point[0] << ";" << point[1] << ")" << std::endl;

  test_surface();
  return EXIT_SUCCESS;
}

void test_surface(void)
{
  const size_t v_step = 2;
  const size_t u_step = 2;

  std::array<vec3, 4> ctrl_points;

  ctrl_points[0] = vec3(0.0f, 0.0f, 0.0f);
  ctrl_points[1] = vec3(1.0f, 0.0f, 0.0f);
  ctrl_points[2] = vec3(0.0f, 1.0f, 0.0f);
  ctrl_points[3] = vec3(1.0f, 1.0f, 0.0f);

  const float stride_u = 1.0f / static_cast<float>(u_step);
  const float stride_v = 1.0f / static_cast<float>(v_step);

  for (size_t j = 0; j <= v_step; j++)
  {
    const float v = j * stride_v;
    for (size_t i = 0; i <= u_step; i++)
    {
      const float u = i * stride_u;
      vec3 p = horner<vec3, float, 2, 2>(ctrl_points.data(), u, v);
      std::cout << "(" << p[0] << ";" << p[1] << ";" << p[2] << ")" << std::endl;
    }
  }
}