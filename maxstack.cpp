int getmax()
{
  return max;
}

void push(const int &arg) {
  if (!stack.empty()) {
    if (arg > max) {
      max = arg; 
    }
    stack.push(arg);
 }
}


int findmax() {
 stack<int> temparray;
 int max = m_stack.top();
 while(!m_stack.empty()) {
   int value = m_stack.top();
   if (value > max) {
    max = value;
  }
  temparray.push(value);
  m_stack.pop();
  }
  m_stack = temparray;
  return max;
}

void pop() {
   if (
}
