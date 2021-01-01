
/*
* always think of loops in terms of
	processed and to be processed.
*/

function getLsSz(head)
{
	var cnt = 0;
	while(head!=null){
		cnt +=1;
		head = head.next;
		
	}
	return cnt;
}
/*
function reverseLS(head)
{
	if(head == null)
		return null;
	
	if(head.next == null)
		return head;
	
	var prev = head;
	var cur = head.next;
	prev.next = null; // end of the new LS
	
	while(true)
	{
		// hold next 
		var next = cur.next;
		// redirect
		cur.next = prev;
		
		// end 
		if(next == null) 
			break;
		
		else{
			// reconfigure
			prev = cur;
			cur = next;
		}
	}
	return cur;
}*/

function concatLS(leftL, rightL)
{
	if(leftL == null)
		return rightL;
	if(rightL == null)
		return leftL;
	
	var originalHead = leftL;
	while(true)
	{
		if(leftL.next==null){
			leftL.next = rightL;
			break;
		}
		else 
			leftL = leftL.next;
	}
	return originalHead;
}

function cutPreFix(head, k)
{
	// shift left
	var prefixHead = head;
	var prevHead = head;
	
	for(var i=0; i<k; i++){
		head = head.next;
		if(i+1 ==k)
			prevHead.next = null;
		else
			prevHead = prevHead.next;
	}
	
	//prefixHead = reverseLS(prefixHead);
	head = concatLS(head, prefixHead);
	return head;
}

function cutPostFix(head, k, sz)
{
	var postFixHead = head;
	var cnt = 0;
	while(true)
	{
		cnt +=1;
		
		if(sz - cnt == k){// last node in the processed part
			var next = postFixHead.next;
			postFixHead.next = null;
			postFixHead = next;
			break;
		}
		else 
			postFixHead = postFixHead.next;
	}
	
	//postFixHead = reverseLS(postFixHead);
	head = concatLS(postFixHead, head);
	return head;
}

function shiftLinkedList(head, k) {
  // Write your code here
	var sign = k>=0?1:-1;
	k = k>=0?k:-k;
	
	var sz = getLsSz(head);
	k = k % sz;
	if(k==0)
		return head;
	if(sign == 1)
		head = cutPostFix(head, k, sz);	
	else
		head = cutPreFix(head, k);
	
	return head;
}

// This is the class of the input linked list.
class LinkedList {
  constructor(value) {
    this.value = value;
    this.next = null;
  }
}

// Do not edit the line below.
exports.shiftLinkedList = shiftLinkedList;
