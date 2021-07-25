package llcycle

type ListNode struct {
     Val int
     Next *ListNode
}

func hasCycleV1(head *ListNode) bool {
    if head == nil || head.Next == nil {
    	return false
	}

	it1 := head
	it2 := head.Next.Next

	for it1 != nil && it2 != nil {
		if it1 == it2 {
			return true
		}

		if it2.Next == nil {
			return false
		}

		it1 = it1.Next
		it2 = it2.Next.Next
	}

	return false
}

func hasCycleV2(head *ListNode) bool {
	nodes := make(map[*ListNode]struct{})

	for head != nil {
		if _, ok := nodes[head]; ok {
			return true
		}

		nodes[head] = struct{}{}
		head = head.Next
	}

	return false
}

func hasCycleV3(head *ListNode) bool {
	if head == nil {
		return false
	}

	slow, fast := head, head.Next

	for fast != nil && fast.Next != nil {
		if slow == fast {
			return true
		}

		slow = slow.Next
		fast = fast.Next.Next
	}

	return false
}
