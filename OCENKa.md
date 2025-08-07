# Оценка по памяти

int calc(int* arr, int size)        | 
{                                   |
  int ans = 0;                      | + 1 (int ans)
  for (int i = 1; i < size; i++)    | + 1 (int i)
  {                                 |
    ans += arr[i] - arr[i-1];       |
  }                                 |
  return ans;                       |
}                                   |

 ## Итого: 2  ->  O(1)

# Оценка по времени

int calc(int* arr, int size)        |
{                                   |
  int ans = 0;                      | + 1 (Присвоение значения)
  for (int i = 1; i < size; i++)    | + (n-1) (Проход по массиву, пропуская первый элемент)
  {                                 |
    ans += arr[i] - arr[i-1];       | + 1 (Обращение к ячейке памяти),  +1 (i - 1),  +1 (Обращение к ячейке памяти)
  }                                 |
  return ans;                       | + 1
}                                   |

## Итого: 1 + (n-1) * [1 + 1 + 1] + 1 = 3n - 1 -> O(n)