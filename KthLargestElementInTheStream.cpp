/*# Intuition
The problem requires us to efficiently track the k-th largest element in a dynamic stream of numbers. A min-heap (priority queue) is well-suited for this task since it allows us to maintain the k largest elements encountered so far, with the smallest of these being the k-th largest.

# Approach
1. **Initialization**:
   - Create a min-heap to store the k largest elements.
   - Iterate through the initial list `nums` and add each element to the heap using the `add` method.
   
2. **Adding New Elements**:
   - Add the new element to the heap.
   - If the heap exceeds size `k`, remove the smallest element (which will be at the top of the min-heap).
   - The element at the top of the heap is now the k-th largest element.

# Complexity
- **Time complexity**: $$O(n \log k)$$
  - Adding an element to the heap takes $$O(\log k)$$ time.
  - Constructing the heap with `n` elements takes $$O(n \log k)$$ time.
- **Space complexity**: $$O(k)$$
  - The space used by the heap is proportional to `k`.

# Code
```cpp*/
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
    
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num: nums) {
            add(num);
        }
    }

    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top();
    }
};

auto init = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
