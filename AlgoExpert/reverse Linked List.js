/*
* this is not actually a problem 
  but a code portion that I wrote for other problem
*
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
}
