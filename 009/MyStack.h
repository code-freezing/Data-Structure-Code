
enum ErrorCode
{
	success,
	underflow,
	overflow
};

const int maxStack = 100;

template <class StackEntry>
class MyStack
{
public:
	MyStack()
	{
		size = 0;
	}

	bool empty() const { return size == 0; }

	ErrorCode pop()
	{
		if (size > 0)
		{
			size--;
			return success;
		}
		else {
			return underflow;
		}
	}

	ErrorCode top(StackEntry& item) const
	{
		if (size > 0)
		{
			item = entry[size - 1];
			return success;
		}
		else {
			return underflow;
		}
	}

	ErrorCode push(const StackEntry& item)
	{
		if (size < maxStack)
		{
			entry[size++] = item;
			return success;
		}
		else {
			return overflow;
		}
	}

private:
	int size;
	StackEntry entry[maxStack];
};
