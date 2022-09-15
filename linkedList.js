class Node
{
    constructor(value=-9999,next=null)
    {
        this.value=value;
        this.next=next;
    }
}
class LinkedList{
    constructor(head=null,length=0)
    {
        this.head=head;
        this.length=length;
    }
    isEmpty()
    {
        return (this.head==null);
    }
    insertAtStart(value)
    {
        var newNode=new Node(value);
        if(this.isEmpty())
        {
            this.head=newNode;
            this.length++;
            return;
        }
        else
        {
            newNode.next=this.head;
            this.head=newNode;
            this.length++;
        }
    }
    insertAtLast(value)
    {
        var newNode=new Node(value);
        if(this.isEmpty())
        {
            this.head=newNode;
            this.length++;
            return;
        }
        else
        {
            var temp=this.head;
            while(temp.next!=null)
            {
                temp=temp.next;
            }
            temp.next=newNode;
            this.length++;
        }        
    }
    removeFRomStart()
    {
        if(this.length==1)
        {
            this.head=null;
        }
        if(this.isEmpty())
        {
            console.log('LinkedList is empty');
            return;
        }
        else
        {
            var temp=this.head.next;
            this.head=null;
            this.head=temp;
            this.length--;
        }
    }
    removeFromEnd()
    {
        if(this.length==1)
        {
            this.head=null;
        }
        if(this.isEmpty())
        {
            console.log('Linkedlist is empty');
            return;
        }
        else
        {
            var last=this.head.next;
            var secondLast=this.head;
            while(last.next != null)
            [
                last=last.next,
                secondLast=secondLast.next,
            ]
            last=null;
            secondLast.next=null;
            this.length--;
        }
    }
    display()
    {
        var temp=this.head;
        while(temp!=null)
        {
            console.log(temp.value);
            temp=temp.next;
        }
        console.log('NULL');
    }
}
var l1 = new LinkedList();
for(var i=1;i<=10;i++)
{
l1.insertAtLast(i);
l1.insertAtStart(i);
}
l1.display();

for(var i=1;i<=10;i++)
{
    l1.removeFRomStart();
    l1.removeFromEnd();
}
