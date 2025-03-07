#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(loc >= size_){
    return NULL;
  }
  Item* temp = head_;
  size_t count = 0;
  while(temp != NULL){
    if(loc < count + temp->last - temp->first){
      return &(temp->val[temp->first + (loc - count)]);
    }
    count += temp->last - temp->first;
    temp = temp->next;
  }
  return NULL;
}

std::string const & ULListStr::back() const
{
  if(tail_ == NULL){
    throw std::out_of_range("Empty list");
  }
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const
{
  if(head_ == NULL){
    throw std::out_of_range("Empty list");
  }
  return head_->val[head_->first];
}

void ULListStr::push_back(const std::string& val)
{
  if(tail_ == NULL || tail_->last == ARRSIZE){
    Item* temp = new Item();
    temp->val[0] = val;
    temp->first = 0;
    temp->last = 1;
    temp->prev = tail_;
    if(tail_ != NULL){
      tail_->next = temp;
    }
    else{
      head_ = temp;
    }
    tail_ = temp;
  }
  else{
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  size_++;
}

void ULListStr::push_front(const std::string& val)
{
  if(head_ == NULL || head_->first == 0){
    Item* temp = new Item();
    temp->val[ARRSIZE - 1] = val;
    temp->first = ARRSIZE - 1;
    temp->last = ARRSIZE;
    temp->next = head_;
    if(head_ != NULL){
      head_->prev = temp;
    }
    else{
      tail_ = temp;
    }
    head_ = temp;
  }
  else{
    head_->first--;
    head_->val[head_->first] = val;
  }
  size_++;
}

void ULListStr::pop_back()
{
  if(tail_ == NULL){
    throw std::out_of_range("Empty list");
  }
  tail_->last--;
  if(tail_->last == tail_->first){
    Item* temp = tail_;
    tail_ = tail_->prev;
    if(tail_ != NULL){
      tail_->next = NULL;
    }
    else{
      head_ = NULL;
    }
    delete temp;
  }
  size_--;
}

void ULListStr::pop_front()
{
  if(head_ == NULL){
    throw std::out_of_range("Empty list");
  }
  head_->first++;
  if(head_->first == head_->last){
    Item* temp = head_;
    head_ = head_->next;
    if(head_ != NULL){
      head_->prev = NULL;
    }
    else{
      tail_ = NULL;
    }
    delete temp;
  }
  size_--;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
