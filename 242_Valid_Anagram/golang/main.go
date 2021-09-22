package golang

import (
	"strings"
)

func getSortedKey(s string) string {
	t := [26]int32{}

	for _, c := range s {
		t[c-'a']++
	}

	var b strings.Builder

	for _, v := range t {
		b.WriteString(string(v))
	}

	return b.String()
}

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	return getSortedKey(s) == getSortedKey(t)
}

func isAnagramV2(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	m := make(map[int32]int, 26)

	for _, c := range s {
		m[c]++
	}

	for _, c := range t {
		m[c]--
	}

	for _, v := range m {
		if v != 0 {
			return false
		}
	}

	return true
}

func isAnagramV3(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	b := [26]int32{}

	for i := range s {
		b[s[i]-'a']++
		b[t[i]-'a']--
	}

	for _, v := range b {
		if v != 0 {
			return false
		}
	}

	return true
}