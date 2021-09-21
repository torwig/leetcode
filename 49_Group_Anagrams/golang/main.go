package golang

const lettersInAlphabet = 26

func groupAnagrams(strs []string) [][]string {
    groups := make(map[[lettersInAlphabet]int][]string)

    for _, s := range strs {
    	t := [lettersInAlphabet]int{}
    	for _, c := range s {
    		t[c - 'a']++
		}

		groups[t] = append(groups[t], s)
	}

	result := make([][]string, 0)

	for _, g := range groups {
		result = append(result, g)
	}

	return result
}
