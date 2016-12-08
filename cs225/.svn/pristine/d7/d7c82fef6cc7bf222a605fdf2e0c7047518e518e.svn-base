/**
 * @file heap.cpp
 * Implementation of a heap class.
 */

template <class T, class Compare>
size_t heap<T, Compare>::root() const
{
    /// @todo Update to return the index you are choosing to be your root.
    return 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::leftChild(size_t currentIdx) const
{
    /// @todo Update to return the index of the left child.
    return 2*currentIdx;
}

template <class T, class Compare>
size_t heap<T, Compare>::rightChild(size_t currentIdx) const
{
    /// @todo Update to return the index of the right child.
    return 2*currentIdx+1;
}

template <class T, class Compare>
size_t heap<T, Compare>::parent(size_t currentIdx) const
{
    /// @todo Update to return the index of the parent.
    return currentIdx/2;
}

template <class T, class Compare>
bool heap<T, Compare>::hasAChild(size_t currentIdx) const
{
    if((currentIdx*2)<_elems.size())
    return true;/// @todo Update to return whether the given node has a child
    return false;
}

template <class T, class Compare>
size_t heap<T, Compare>::maxPriorityChild(size_t currentIdx) const
{
    /// @todo Update to return the index of the child with highest priority
    ///   as defined by higherPriority()
    if(!hasAChild(currentIdx))
        return 0;
    if(rightChild(currentIdx)>=_elems.size())
        return leftChild(currentIdx);
    if(higherPriority(_elems[leftChild(currentIdx)],_elems[rightChild(currentIdx)]))
            return leftChild(currentIdx);
        else
            return rightChild(currentIdx);
    
}

template <class T, class Compare>
void heap<T, Compare>::heapifyDown(size_t currentIdx)
{
   if(hasAChild(currentIdx))
   {
    size_t bigger = maxPriorityChild(currentIdx);
    if(!higherPriority(_elems[currentIdx],_elems[bigger]))
     {   std::swap(_elems[bigger],_elems[currentIdx]);
         heapifyDown(bigger);
     }
      } /// @todo Implement the heapifyDown algorithm.
}

template <class T, class Compare>
void heap<T, Compare>::heapifyUp(size_t currentIdx)
{
    if (currentIdx == root())
        return;
    size_t parentIdx = parent(currentIdx);
    if (higherPriority(_elems[currentIdx], _elems[parentIdx])) {
        std::swap(_elems[currentIdx], _elems[parentIdx]);
        heapifyUp(parentIdx);
    }
}

template <class T, class Compare>
heap<T, Compare>::heap()
{
    /// @todo Depending on your implementation, this function may or may
    ///   not need modifying
    size = 0;
    _elems.push_back(T());
}

template <class T, class Compare>
heap<T, Compare>::heap(const std::vector<T>& elems)
{
    _elems.push_back(T());
    size = 0;
    for(size_t i = 0; i < elems.size();i++)
        {
            _elems.push_back(elems[i]);
            size++;
        }
    for(size_t i = parent(size);i>0;i--)
        heapifyDown(i);
    /// @todo Construct a heap using the buildHeap algorithm
}

template <class T, class Compare>
T heap<T, Compare>::pop()
{
    if(size == 0)
        return T();
    /// @todo Remove, and return, the element with highest priority
    T min = _elems[1];
    _elems[1] = _elems[size];
    _elems.pop_back();
    size--;
    heapifyDown(1);
    return min;
   // return T();
}

template <class T, class Compare>
T heap<T, Compare>::peek() const
{
    /// @todo Return, but do not remove, the element with highest priority
    if(size!=0)
    return _elems[1];
    return T();
}

template <class T, class Compare>
void heap<T, Compare>::push(const T& elem)
{
    size++;
    _elems.push_back(elem);
    heapifyUp(size);/// @todo Add elem to the heap
}

template <class T, class Compare>
bool heap<T, Compare>::empty() const
{
    /// @todo Determine if the heap is empty
    return (_elems.size() == 1);
}
