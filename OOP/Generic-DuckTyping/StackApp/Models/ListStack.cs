using StackApp.Contract;
namespace StackApp.Models;

public class ListStack<T> : IStack<T>
// where T : IComperable , class , new() 
// gibi gibi kısıtlamalar yapabiliriz.
{
    private List<T> _collection;

    private int _LastIndex => _collection.Count - 1;

    public ListStack()
    {
        _collection = new List<T>();
    }

    public ListStack(IEnumerable<T> collection)
    : this()  // new leme işlemini yapıyoruz yukardaki cons dan alıp.
    {
        foreach (var item in collection)
        {
            Push(item);
        }
    }

    public T Peek()
    {
        return _collection[_LastIndex];
    }

    public T Pop()
    {
        var temp = _collection[_LastIndex];
        _collection.RemoveAt(_LastIndex);
        return temp;
    }

    public void Push(T item)
    {
        _collection.Add(item);
    }
}