package main

import (
	"testing"
)

func TestMergeKListsV1(t *testing.T) {
	l := []*ListNode{
		{
			Val: 1,
			Next: &ListNode{
				Val: 3,
				Next: &ListNode{
					Val:  5,
					Next: nil,
				},
			},
		},
		{
			Val: 2,
			Next: &ListNode{
				Val: 4,
				Next: &ListNode{
					Val:  6,
					Next: nil,
				},
			},
		},
		{
			Val: 7,
			Next: &ListNode{
				Val:  8,
				Next: nil,
			},
		},
		nil,
		{
			Val:  9,
			Next: nil,
		},
	}

	result := mergeKListsV1(l)
	i := 1

	for result != nil {
		if result.Val != i {
			t.Errorf("want %d, got %d", i, result.Val)
		}
		result = result.Next

		i += 1
	}
}
