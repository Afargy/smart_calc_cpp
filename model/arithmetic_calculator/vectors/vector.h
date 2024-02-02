#ifndef CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_VECTORS_VECTOR_H_
#define CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_VECTORS_VECTOR_H_

#include <memory>
#include <vector>

namespace s21 {
template <class T>
class Vector {
 public:
  std::shared_ptr<std::vector<T>> operator->() { return vector_; }
  virtual void PushBack(const T& elem) { vector_->push_back(elem); };
  T PopBack() {
    T temp = vector_->back();
    vector_->pop_back();
    return temp;
  };
  size_t Size() const noexcept { return vector_->size(); };
  T& At(size_t i) const noexcept { return vector_->at(i); }
  T& operator[](size_t i) const noexcept { return vector_->at(i); }
  bool IsEmpty() const noexcept { return !vector_->size(); };
  bool NotEmpty() const noexcept { return vector_->size(); };
  T& Back() const { return vector_->back(); }
  T& Back() { return vector_->back(); }
  void Clear() noexcept { return vector_->clear(); }

 protected:
  std::shared_ptr<std::vector<T>> vector_{std::make_shared<std::vector<T>>()};
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_SRC_MODEL_ARITHMETIC_CALCULATOR_VECTORS_VECTOR_H_
