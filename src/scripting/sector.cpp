//  SuperTux
//  Copyright (C) 2015 Ingo Ruhnke <grumbel@gmail.com>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "scripting/sector.hpp"

#include "object/gradient.hpp"
#include "supertux/sector.hpp"

namespace scripting {

Sector::Sector(::Sector* parent) :
  m_parent(parent)
{
}

Sector::~Sector()
{
}

void
Sector::set_ambient_light(float red, float green, float blue)
{
  m_parent->set_ambient_light(red, green, blue);
}

float
Sector::get_ambient_red() const
{
  return m_parent->get_ambient_red();
}

float
Sector::get_ambient_green() const
{
  return m_parent->get_ambient_green();
}

float
Sector::get_ambient_blue() const
{
  return m_parent->get_ambient_blue();
}

void
Sector::set_gradient_direction(const std::string& direction)
{
  auto gradient = m_parent->get_background_gradient();
  if(gradient == NULL)
  {
    log_info << "No background gradient found" << std::endl;
    return;
  }

  if(direction == "horizontal")
    gradient->set_direction(GradientDirection::HORIZONTAL);
  else if(direction == "vertical")
    gradient->set_direction(GradientDirection::VERTICAL);
  else if(direction == "horizontal_sector")
    gradient->set_direction(GradientDirection::HORIZONTAL_SECTOR);
  else if(direction == "vertical_sector")
    gradient->set_direction(GradientDirection::VERTICAL_SECTOR);
  else
    log_info << "Invalid direction for gradient \"" << direction << "\"";
}

std::string
Sector::get_gradient_direction() const
{
  auto gradient = m_parent->get_background_gradient();
  if(gradient == NULL)
  {
    log_info << "No background gradient found" << std::endl;
    return NULL;
  }

  auto direction = gradient->get_direction();

  if(direction == GradientDirection::HORIZONTAL)
    return "horizontal";
  if(direction == GradientDirection::VERTICAL)
    return "vertical";
  if(direction == GradientDirection::HORIZONTAL_SECTOR)
    return "horizontal_sector";
  if(direction == GradientDirection::VERTICAL_SECTOR)
    return "vertical_sector";

  return NULL;
}

void
Sector::set_gradient_color1(float red, float green, float blue)
{
  auto gradient = m_parent->get_background_gradient();
  if(gradient == NULL)
  {
    log_info << "No background gradient found" << std::endl;
    return ;
  }
  gradient->set_gradient(Color(red, green, blue), gradient->get_gradient_bottom());
}

void
Sector::set_gradient_color2(float red, float green, float blue)
{
  auto gradient = m_parent->get_background_gradient();
  if(gradient == NULL)
  {
    log_info << "No background gradient found" << std::endl;
    return;
  }
  gradient->set_gradient(gradient->get_gradient_top(), Color(red, green, blue));
}

void
Sector::set_gravity(float gravity)
{
  m_parent->set_gravity(gravity);
}

} // namespace scripting

/* EOF */