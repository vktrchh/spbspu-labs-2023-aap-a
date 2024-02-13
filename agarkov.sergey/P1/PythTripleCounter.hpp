#ifndef PYTHTRIPLECOUNTER_HPP 
#define PYTHTRIPLECOUNTER_HPP 

namespace agarkov
{
  struct PythTripleCounter
  {
  public:
    PythTripleCounter();
    void operator()(int cur);
    int getCount();
  private:
    size_t count;
    int first;
    int second;
    int third;
  };
}

#endif
