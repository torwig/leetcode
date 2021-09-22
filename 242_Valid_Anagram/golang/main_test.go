package golang

import (
	"fmt"
	"testing"
)

func Test_isAnagram(t *testing.T) {
	var tests = []struct {
		first  string
		second string
		result bool
	}{
		{"rat", "tar", true},
		{"anagram", "ganaram", true},
		{"smoke", "stock", false},
		{"deep", "sheep", false},
		{"mix", "pixie", false},
	}

	for _, tt := range tests {
		t.Run(fmt.Sprintf("%s vs %s", tt.first, tt.second), func(t *testing.T) {
			ok := isAnagramV3(tt.first, tt.second)
			if ok != tt.result {
				t.Errorf("got %t, want %t", ok, tt.result)
			}
		})
	}
}
