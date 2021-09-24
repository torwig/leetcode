package golang

import (
	"fmt"
	"testing"
)

func Test_isValid(t *testing.T) {
	var tests = []struct {
		input  string
		result bool
	}{
		{"", true},
		{"(((", false},
		{"(}", false},
		{"{]", false},
		{"[)", false},
		{"{()}", true},
		{"[(}]", false},
	}

	for _, tt := range tests {
		t.Run(fmt.Sprintf("checking %s", tt.input), func(t *testing.T) {
			valid := isValid(tt.input)

			if valid != tt.result {
				t.Errorf("got %t, want %t", valid, tt.result)
			}
		})
	}
}
