#include <vector>

template <typename T, typename Compare=std::greater<T>>
class PriorityQueue
{
    protected:

    //the priority queue
    std::vector<T> p_queue;
    //comparator used for determining if the PriorityQueue is max-oriented
    //or min-oriented
    Compare greater_than;

    //computes the parent of a given position
    size_t parent(size_t j) { return (j-1) / 2; }
    //computes the left child of a given position
    size_t left(size_t j) { return 2 * j + 1; }
    //computes the right child of a given position
    size_t right(size_t j) { return 2 * j + 2; }
    //returns whether or not a position has a left child
    bool has_left(size_t j) { return left(j) < p_queue.size(); }
    //returns whether or not a position has a right child
    bool has_right(size_t j) { return right(j) < p_queue.size(); }
    
    //moves a given position up the heap to preserve its configuration as
    //max-oriented (or min-oriented if configured as such)
    void upheap(size_t j)
    {
        while (j > 0) 
        {
            size_t p{parent(j)};

            if (greater_than(p_queue[j], p_queue[p])) 
            {
                std::swap(p_queue[j], p_queue[p]);
                j = p;
            } 
            else
            {
                break;
            }
        }
    }
    
    //moves a given position down the heap to preserve its configuration as
    //max-oriented (or min-oriented if configured as such)
    void downheap(size_t j) 
    {
        while (has_left(j)) 
        {
            size_t large_child{left(j)};

            if (has_right(j)) 
            {
                if (greater_than(p_queue[right(j)], p_queue[left(j)]))
                {
                    large_child = right(j);
                }
            }

            if (greater_than(p_queue[large_child], p_queue[j])) 
            {
                std::swap(p_queue[j], p_queue[large_child]);
                j = large_child;
            } 
            else
            {
                break;
            }
        }
    }

  public:
  
  PriorityQueue()
  :
  p_queue{},
  greater_than{}
  {
  }

  //returns the size of the PriorityQueue
  size_t size() const 
  { 
    return p_queue.size();
  }

  //returns whether or not the PriorityQueue is empty
  bool empty() const 
  { 
    return p_queue.empty(); 
  }

  //returns the highest priority entry in the PriorityQueue
  const T& max() const 
  { 
    return p_queue.front(); 
  }

  //inserts a new entry into the PriorityQueue
  void insert(const T& elem) 
  {
    p_queue.push_back(elem);
    upheap(p_queue.size() - 1);
  }

  //removes the entry at the beginning of the PriorityQueue
  void remove_max() 
  {
    std::swap(p_queue[0], p_queue[p_queue.size() - 1]);
    p_queue.pop_back();
    downheap(0);
  }
};
