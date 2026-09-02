using StackApp.Contract;
namespace StackApp.Models;

public class LinkedListStack<T> : IStack<T>
//where T : class, new(), IComparable
{
    private LinkedList<T> _collection;
    public LinkedListStack()
    {
        _collection = new LinkedList<T>();
    }

    public LinkedListStack(IEnumerable<T> collection) 
    : this()  // new leme işlemini yapıyoruz yukardaki cons dan alıp.
    {
        foreach (var item in collection)
        {
            Push(item);
        }
    }

    public T Peek()
    {
        return _collection.First.Value;
    }

    public T Pop()
    {
        var temp = _collection.First.Value;
        _collection.RemoveFirst();
        return temp;
    }

    public void Push(T item)
    {
        _collection.AddFirst(item);
    }
}