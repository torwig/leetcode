package main

import (
	"container/heap"
	"sort"
)

type ListNode struct {
	Val  int
	Next *ListNode
}

// mergeKListsV1 merges k sorted lists
func mergeKListsV1(lists []*ListNode) *ListNode {
	var (
		head *ListNode
		tail *ListNode
	)

	for {
		var (
			minNode         *ListNode
			minNodePosition int
		)

		for i, node := range lists {
			if node == nil {
				continue
			}

			if minNode == nil {
				minNode = node
				minNodePosition = i

				continue
			}

			if minNode.Val > node.Val {
				minNode = node
				minNodePosition = i
			}
		}

		if minNode == nil {
			break
		}

		lists[minNodePosition] = minNode.Next
		minNode.Next = nil

		if head != nil {
			tail.Next = minNode
			tail = tail.Next
		} else {
			head = minNode
			tail = minNode
		}
	}

	return head
}

// mergeKListsV2 merges k sorted lists
// grab all values into slice => sort slice => create new list
func mergeKListsV2(lists []*ListNode) *ListNode {
	if len(lists) == 0 {
		return nil
	}

	var n []int

	for i := 0; i < len(lists); i++ {
		p := lists[i]

		for p != nil {
			n = append(n, p.Val)
			p = p.Next
		}
	}

	if len(n) == 0 {
		return nil
	}

	sort.Ints(n)

	head := &ListNode{Val: n[0]}
	current := head

	for i := 1; i < len(n); i++ {
		current.Next = &ListNode{Val: n[i]}
		current = current.Next
	}

	return head
}

type NodeHeap []*ListNode

func (h NodeHeap) Len() int           { return len(h) }
func (h NodeHeap) Less(i, j int) bool { return h[i].Val <= h[j].Val }
func (h NodeHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

func (h *NodeHeap) Push(x interface{}) {
	*h = append(*h, x.(*ListNode))
}

func (h *NodeHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

// mergeKListsV3 merges k sorted lists using heap
func mergeKListsV3(lists []*ListNode) *ListNode {
	mergeHeap := &NodeHeap{}
	heap.Init(mergeHeap)

	for i := 0; i < len(lists); i++ {
		if lists[i] != nil {
			heap.Push(mergeHeap, lists[i])
		}
	}

	var head *ListNode
	var tail *ListNode
	var next *ListNode

	for mergeHeap.Len() > 0 {
		if tail != nil {
			next = heap.Pop(mergeHeap).(*ListNode)
			if next.Next != nil {
				heap.Push(mergeHeap, next.Next)
			}
			tail.Next = next
			tail = next
		} else {
			head = heap.Pop(mergeHeap).(*ListNode)
			tail = head
			if head.Next != nil {
				heap.Push(mergeHeap, head.Next)
			}
		}
	}

	return head
}
