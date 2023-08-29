def find_max_modules(n, dependent, primary):
  """
  Finds the maximum number of modules that Leo can code.

  Args:
    n: The number of modules.
    dependent: The array of dependent modules.
    primary: The array of primary modules.

  Returns:
    The maximum number of modules that Leo can code.
  """

  # Create a graph of dependencies.
  graph = {}
  for i in range(n):
    graph[i] = []
  for i, dependent_module in enumerate(dependent):
    graph[primary[i]].append(dependent_module)

  # Initialize a queue with the modules that do not depend on any other modules.
  queue = []
  for i in range(n):
    if not graph[i]:
      queue.append(i)

  # Count the number of modules that Leo can code.
  count = 0
  while queue:
    module = queue.pop(0)
    count += 1

    # Remove all modules that depend on the current module from the queue.
    for dependent_module in graph[module]:
      graph[dependent_module].remove(module)
      if not graph[dependent_module]:
        queue.append(dependent_module)

  return count


if __name__ == "__main__":
  n = int(input())
  m = int(input())
  dependent = [int(input()) for _ in range(m)]
  primary = [int(input()) for _ in range(m)]

  print(find_max_modules(n, dependent, primary))

