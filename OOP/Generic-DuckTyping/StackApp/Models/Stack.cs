using StackApp.Contract;
namespace StackApp.Models;

public class Stack<T> : IStack<T>
{
    private IStack<T> _stack;

    

    public Stack()
    {
        _stack = new LinkedListStack<T>();
    }

    public Stack(IEnumerable<T> collection)
    : this()  // new leme işlemini yapıyoruz yukardaki cons dan alıp.
    {
        foreach (var item in collection)
        {
            Push(item);
        }
    }


    public T Peek()
    {
        return _stack.Peek();
    }

    public T Pop()
    {
        return _stack.Pop();
    }

    public void Push(T item)
    {
        _stack.Push(item);
    }
}