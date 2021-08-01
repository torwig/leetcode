package golang

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseListV1(head *ListNode) *ListNode {
	tmp := head
	var newHead *ListNode

	for tmp != nil {
		head = head.Next
		tmp.Next = newHead
		newHead = tmp
		tmp = head
	}

	return newHead
}

func reverseListV2(head *ListNode) *ListNode {
	curr := head
	var prev *ListNode

	for curr != nil {
		tmp := curr.Next
		curr.Next = prev
		prev = curr
		curr = tmp
	}

	return prev
}

// reverseListV3 use recursion
func reverseListV3(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	p := reverseListV3(head.Next)
	head.Next.Next = head
	head.Next = nil

	return p
}
