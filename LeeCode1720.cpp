#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define ll long long

class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<int> arr(encoded.size() + 1);
        arr[0] = first;

        for (int i = 0; i < encoded.size(); i++) {
            arr[i + 1] = encoded[i] ^ arr[i];
        }
        return arr;
    }
};

/*
# Intuition
The problem requires decoding an encoded array where each element is derived from XORing consecutive elements of the original array. Given the first element of the original array and the encoded array, we can reconstruct the original array.

# Approach
1. Initialize the result array with the size of `encoded` array plus one, and set the first element to `first`.
2. Iterate through the `encoded` array and reconstruct each subsequent element by XORing the current encoded value with the previous element in the result array.
3. Return the reconstructed array.

# Complexity
- Time complexity:
  $$O(n)$$ where `n` is the length of the `encoded` array. We iterate through the `encoded` array once.

- Space complexity:
  $$O(n)$$ where `n` is the length of the `encoded` array. The space is used to store the resulting array.

# Dry Run
Let's dry run the example `encoded = [6, 2, 7, 3]` and `first = 4`:

1. **Initialization**:
   - `encoded = [6, 2, 7, 3]`
   - `first = 4`
   - `arr = [4]`

2. **First Iteration** (`i = 0`):
   - `arr[1] = encoded[0] ^ arr[0] = 6 ^ 4 = 2`
   - `arr = [4, 2]`

3. **Second Iteration** (`i = 1`):
   - `arr[2] = encoded[1] ^ arr[1] = 2 ^ 2 = 0`
   - `arr = [4, 2, 0]`

4. **Third Iteration** (`i = 2`):
   - `arr[3] = encoded[2] ^ arr[2] = 7 ^ 0 = 7`
   - `arr = [4, 2, 0, 7]`

5. **Fourth Iteration** (`i = 3`):
   - `arr[4] = encoded[3] ^ arr[3] = 3 ^ 7 = 4`
   - `arr = [4, 2, 0, 7, 4]`

The dry run confirms that the solution correctly decodes the array to `[4, 2, 0, 7, 4]`.
*/
