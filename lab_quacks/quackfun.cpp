/**
 * @file quackfun.cpp
 * This is where you will implement the required functions for the
 *  stacks and queues portion of the lab.
 */

/**
 * Sums items in a stack.
 * @param s A stack holding values to sum.
 * @return The sum of all the elements in the stack, leaving the original
 *  stack in the same state (unchanged).
 *
 * @note You may modify the stack as long as you restore it to its original
 *  values.
 * @note You may use only two local variables of type T in your function.
 *  Note that this function is templatized on the stack's type, so stacks of
 *  objects overloading the + operator can be summed.
 * @note We are using the Standard Template Library (STL) stack in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint Think recursively!
 */
template <typename T>
T QuackFun::sum(stack<T> & s)
{
	T temp = s.top();
	s.pop();
	if(s.empty())
	{
	s.push(temp);
	return temp;
	}
	else
	{
	T sumBefore = sum(s);
	s.push(temp);
	return temp+sumBefore;
	}
}

/**
 * Reverses even sized blocks of items in the queue. Blocks start at size
 * one and increase for each subsequent block.
 * @param q A queue of items to be scrambled
 *
 * @note Any "leftover" numbers should be handled as if their block was complete.
 * @note We are using the Standard Template Library (STL) queue in this
 *  problem. Its pop function works a bit differently from the stack we
 *  built. Try searching for "stl stack" to learn how to use it.
 * @hint You'll want to make a local stack variable.
 */
template <typename T>
void QuackFun::scramble(queue<T> & q)
{
	stack<T> s;
	int blockNumber = 1;
	int trackOfComplete = 0;
	int size = int(q.size());
	while(trackOfComplete < size)
	{
	if(blockNumber%2==1)//odd block, just move 
	{
	int tempMin = blockNumber;
	if(tempMin > size-trackOfComplete)
	tempMin = size-trackOfComplete;
	for(int i = 0; i < tempMin; i++)
		{
		q.push(q.front());
		q.pop();
		}
	trackOfComplete += tempMin;
	blockNumber++;
	}
	else//even block, reverse
	{
	int tempMin = blockNumber;
	if(tempMin > size-trackOfComplete)
	tempMin = size-trackOfComplete;
	for(int i = 0; i < tempMin; i++)
		{
		s.push(q.front());
		q.pop();
		}
	for(int i = 0; i < tempMin; i++)
		{
		q.push(s.top());
		s.pop();
		}
	trackOfComplete += tempMin;
	blockNumber++;
	}
	}
}


/**
 * @return true if the parameter stack and queue contain only elements of exactly
 *  the same values in exactly the same order; false, otherwise.
 *
 * @note You may assume the stack and queue contain the same number of items!
 * @note There are restrictions for writing this function.
 * - Your function may not use any loops
 * - In your function you may only declare ONE local boolean variable to use in your return statement,
 *      and you may only declare TWO local variables of parametrized type T to use however you wish.
 *   No other local variables can be used.
 * - After execution of verifySame, the stack and queue must be unchanged. Be sure to comment your code VERY well.
 */
template <typename T>
bool QuackFun::verifySame(stack<T> & s, queue<T> & q)
{
	bool retval = true; // optional
	if(s.empty())//this means the stack has go to the base case
	return true;
	T temp = s.top();//the content of stack will store in each temp in each recursion
	s.pop();
	retval = verifySame(s, q);//when the base case happen, s will remain empty, q will remain identical
	retval = (retval && (temp == q.front()));
	q.push(q.front());
	q.pop();//the first element in q will be the last
     	s.push(temp);//retrieve the previous s
	return retval;
}

