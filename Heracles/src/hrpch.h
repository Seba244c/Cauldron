//
// Created by Sebastian Snoer on 17/07/2024.
//

#pragma once

#include <string>
#include <unordered_map>
#include <vector>

#include <format>

#include <boost/algorithm/string.hpp>
#include <boost/foreach.hpp>
#include <boost/ptr_container/ptr_vector.hpp>

#define HR_ASSERT(check, msg, ...) { if(!(check)) { throw std::runtime_error(std::format(msg, __VA_ARGS__)); } }
