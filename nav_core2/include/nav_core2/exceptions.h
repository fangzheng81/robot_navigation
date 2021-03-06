/*
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2017, Locus Robotics
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the copyright holder nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef NAV_CORE2_EXCEPTIONS_H
#define NAV_CORE2_EXCEPTIONS_H

#include <stdexcept>
#include <string>
#include <memory>

namespace nav_core2
{

class PlannerException: public std::runtime_error
{
public:
  explicit PlannerException(const std::string description) : std::runtime_error(description) {}
  typedef std::shared_ptr<PlannerException> Ptr;
};

/**
 * @class PlannerTFException
 * @brief Thrown when the planner cannot complete its operation due to TF errors
 */
class PlannerTFException: public PlannerException
{
public:
  explicit PlannerTFException(const std::string description) : PlannerException(description) {}
};

/**
 * @class IllegalTrajectoryException
 * @brief Thrown when one of the critics encountered a fatal error
 */
class IllegalTrajectoryException: public PlannerException
{
public:
  IllegalTrajectoryException(const std::string critic_name, const std::string description)
    : PlannerException(description), critic_name_(critic_name) {}
  std::string getCriticName() const { return critic_name_; }
protected:
  std::string critic_name_;
};

/**
 * @class NoLegalTrajectoriesException
 * @brief Thrown when all the trajectories explored are illegal
 */
class NoLegalTrajectoriesException: public PlannerException
{
public:
  explicit NoLegalTrajectoriesException(const std::string description) : PlannerException(description) {}
};

}  // namespace nav_core2

#endif  // NAV_CORE2_EXCEPTIONS_H
