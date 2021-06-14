//backtracking////////////////////////////////////////////////////


subset///////////////////////////////////////////////////////////////////


vector<vector<int>> subsets(vector<int>& nums) {

	vector<vector<int>>ans;
	vector<int>ds;
	helper(nums, ans, ds, 0);
	return ans;

}
void helper(vector<int>nums , vector<vector<int>> &ans, vector<int>&ds, int h)
{
	if (h > nums.size()) return;
	ans.push_back(ds);


	for (int i = h; i < nums.size(); i++)
	{	//auto it=find(ds.begin(),ds.end(),nums[i]);
		//if(it!=ds.end())continue;
		ds.push_back(nums[i]);
		helper(nums, ans, ds, i + 1);
		ds.pop_back();
	}
}



premutation////////////////////////////////////////////////////////////////////


vector<vector<int>> permute(vector<int>& nums) {


	vector<vector<int>>ans;
	vector<int>ds;
	helper(nums, ans, ds, 0);
	return ans;

}

void helper(vector<int>nums, vector<vector<int>>& ans, vector<int>&ds, int h)
{
	if (h == nums.size())
	{
		ans.push_back(ds);
		return;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		auto it = find(ds.begin(), ds.end(), nums[i]);
		if (it != ds.end())continue;
		ds.push_back(nums[i]);
		helper(nums, ans, ds, h + 1);
		ds.pop_back();

	}
}




Subsets II (contains duplicates)////////////////////////////////////////////////////////

public List<List<Integer>> subsetsWithDup(int[] nums) {
	List<List<Integer>> list = new ArrayList<>();
	Arrays.sort(nums);
	backtrack(list, new ArrayList<>(), nums, 0);
	return list;
}

private void backtrack(List<List<Integer>> list, List<Integer> tempList, int [] nums, int start) {
	list.add(new ArrayList<>(tempList));
	for (int i = start; i < nums.length; i++) {
		if (i > start && nums[i] == nums[i - 1]) continue; // skip duplicates
		tempList.add(nums[i]);
		backtrack(list, tempList, nums, i + 1);
		tempList.remove(tempList.size() - 1);
	}
}






Permutations II (contains duplicates)//////////////////////////////////////////////////////////////////

public List<List<Integer>> permuteUnique(int[] nums) {
	List<List<Integer>> list = new ArrayList<>();
	Arrays.sort(nums);
	backtrack(list, new ArrayList<>(), nums, new boolean[nums.length]);
	return list;
}

private void backtrack(List<List<Integer>> list, List<Integer> tempList, int [] nums, boolean [] used) {
	if (tempList.size() == nums.length) {
		list.add(new ArrayList<>(tempList));
	} else {
		for (int i = 0; i < nums.length; i++) {
			if (used[i] || i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
			used[i] = true;
			tempList.add(nums[i]);
			backtrack(list, tempList, nums, used);
			used[i] = false;
			tempList.remove(tempList.size() - 1);
		}
	}
}





Combination Sum : ///////////////////////////////////////////////////////////////////////////////////////

public List<List<Integer>> combinationSum(int[] nums, int target) {
	List<List<Integer>> list = new ArrayList<>();
	Arrays.sort(nums);
	backtrack(list, new ArrayList<>(), nums, target, 0);
	return list;
}

private void backtrack(List<List<Integer>> list, List<Integer> tempList, int [] nums, int remain, int start) {
	if (remain < 0) return;
	else if (remain == 0) list.add(new ArrayList<>(tempList));
	else {
		for (int i = start; i < nums.length; i++) {
			tempList.add(nums[i]);
			backtrack(list, tempList, nums, remain - nums[i], i); // not i + 1 because we can reuse same elements
			tempList.remove(tempList.size() - 1);
		}
	}
}







Combination Sum II (can't reuse same element) ////////////////////////////////////////////////////////////

                    public List<List<Integer>> combinationSum2(int[] nums, int target) {
                    List<List<Integer>> list = new ArrayList<>();
                    Arrays.sort(nums);
                    backtrack(list, new ArrayList<>(), nums, target, 0);
                    return list;

                    }

                    private void backtrack(List<List<Integer>> list, List<Integer> tempList, int [] nums, int remain, int start){
                    if(remain < 0) return;
                    else if(remain == 0) list.add(new ArrayList<>(tempList));
                    else{
                    for(int i = start; i < nums.length; i++){
                    if(i > start && nums[i] == nums[i-1]) continue; // skip duplicates
                    tempList.add(nums[i]);
                    backtrack(list, tempList, nums, remain - nums[i], i + 1);
                    tempList.remove(tempList.size() - 1);
                    }
                    }
                    }






                    Palindrome Partitioning :////////////////////////////////////////////////////////////////////////////////////////////////

                    public List<List<String>> partition(String s) {
                    List<List<String>> list = new ArrayList<>();
                    backtrack(list, new ArrayList<>(), s, 0);
                    return list;
                    }

                    public void backtrack(List<List<String>> list, List<String> tempList, String s, int start){
                    if(start == s.length())
                    list.add(new ArrayList<>(tempList));
                    else{
                    for(int i = start; i < s.length(); i++){
                    if(isPalindrome(s, start, i)){
                    tempList.add(s.substring(start, i + 1));
                    backtrack(list, tempList, s, i + 1);
                    tempList.remove(tempList.size() - 1);
                    }
                    }
                    }
                    }

                    public boolean isPalindrome(String s, int low, int high){
                    while(low < high)
                    if(s.charAt(low++) != s.charAt(high--)) return false;
                    return true;
                    }