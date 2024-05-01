// Copyright 2024 Shipitsin Alex
#pragma once

#include <cmath>
#include <memory>
#include <utility>
#include <vector>

#include "core/task/include/task.hpp"

using Func = double (*)(double, double);

double shipitsin_flin(double x, double y);
double shipitsin_fxy(double x, double y);
double shipitsin_fysinx(double x, double y);
double shipitsin_fxexpy(double x, double y);

class ShipitsinTaskSequential : public ppc::core::Task {
 public:
  explicit ShipitsinTaskSequential(std::shared_ptr<ppc::core::TaskData> taskData_) : Task(std::move(taskData_)) {}
  bool pre_processing() override;
  bool validation() override;
  bool run() override;
  bool post_processing() override;

 private:
  Func f{};
  double x1{}, x2{}, y1{}, y2{};
  uint64_t n;
  double res;
};
