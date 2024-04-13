#include <iostream>
#include <chrono>
using namespace std;

struct List
{
  int data;
  List *head;
  List *tail;
};

int getNumber ()
{
  int a;
  cin >> a;
  while (cin.fail())
  {
    cin.clear();
    cin.ignore();
    cin >> a;
  }
  return a;
}

List *createList(int length)
{
  List *curr = nullptr;
  List *next = nullptr;
  for (int i = 0; i < length; ++i)
  {
    curr = new List;
    curr->tail = next;
    if (next)
      next->head = curr;
    next = curr;
  }
  curr->head = nullptr;
  return curr;
}

int lenOfList(List *element)
{
  int len = 0;
  while (element != nullptr)
  {
    len += 1;
    element = element->tail;
  }
  return len;
}

void removeList(List *element)
{
  for (int i = 0; i < lenOfList(element); ++i)
  {
    delete element;
    element = element->tail;
  }
}

void printList(List *element)
{
  cout << '{';
  if (!(lenOfList(element) == 1 && element->data == 0))
  {
    while (element != nullptr)
    {
      cout << element->data;
      element = element->tail;
      if (element != nullptr)
        cout << ", ";
    }
  }
  cout << '}';
  cout << endl;
}

List *getElementOfListByIndex(List *element, int index)
{
  List *lookingForElement = element;
  for (int i = 0; i < index; ++i)
    lookingForElement = lookingForElement->tail;
  return lookingForElement;
}

void fillListRandomly(List *element)
{
  while (element != nullptr)
  {
    element->data = rand() % 100;
    element = element->tail;
  }
}

void insertElementToBeginOfTheList(List *element, int input)
{
  List *newElement = new List;
}

void insertElementToEndOfTheList(List *element, int input)
{
  List *lastElement = element;
  for (int i = 0; i < lenOfList(element)-1; ++i)
  {
    lastElement = lastElement->tail;
  }
  List *newElement = new List;
  lastElement->tail = newElement;
  newElement->head = lastElement;
  newElement->tail = nullptr;
  newElement->data = input;
}

void insertElementToSomePositionOfTheList(List *element, int index, int input)
{
  getElementOfListByIndex(element, index)->data = input;
}

List *deleteElementOfTheList(List *element, int index)
{
  List *removingElement = getElementOfListByIndex(element, index);
  List *nextElement = removingElement->tail;
  List *previousElement = removingElement->head;
  if (!previousElement)
  {
    nextElement->head = nullptr;
    element = nextElement;
  }
  else if (!nextElement)
  {
    previousElement->tail = nullptr;
  }
  else
  {
    nextElement->head = previousElement;
    previousElement->tail = nextElement;
  }
  delete removingElement;
  return element;
}

void fillListUserly(List *element)
{
  int number;
  number = getNumber();
  element->data = number;
  while (number != -1)
  {
    number = getNumber();
    insertElementToEndOfTheList(element, number);
  }
  deleteElementOfTheList(element, lenOfList(element)-1);
}

void changeElementsOfTheList(List *element, int index1, int index2)
{
  if (index1 < 0 || index2 < 0 || index1 > lenOfList(element)-1 || index2 > lenOfList(element)-1)
  {
    cout << "incorrect indecies" << endl;
  }
  else 
  {
    List *element1 = getElementOfListByIndex(element, index1); 
    List *element2 = getElementOfListByIndex(element, index2);
    int swappy = element1->data;
    element1->data = element2->data;
    element2->data = swappy;
  }
}

bool correctIndex(int index, int len)
{
  if (index < 0 or index >= len)
    return false;
  return true;
}


int *createDynamicArray(int length)
{
  int *arr = new int[length];
  return arr;
}

void printDynamicArray(int *array, int length)
{
  for (int i = 0; i < length; ++i)
  {
    cout << array[i] << ' ';
  }
  cout << endl;
}

void fillDynamicArrayRandomly(int *array, int length)
{
  for (int i = 0; i < length; ++i)
  {
    array[i] = rand() % 100;
  }
}

void insertElementToEndOfTheDynamicArray(int *array, int *length, int input)
{
  *length += 1;
  array[*length-1] = input;
}

void fillDynamicArrayUserly(int *array, int *length)
{
  int number;
  number = getNumber();
  *array = number;
  while (number != -1)
  {
    number = getNumber();
    insertElementToEndOfTheDynamicArray(array, length, number);
  }
}

void insertToDynamicArray(int *array, int length, int index, int input)
{
  array[index] = input;
}

void changeElementsOfDynamicArray(int *array, int length, int index1, int index2)
{
    int swap = array[index1];
    array[index1] = array[index2];
    array[index2] = swap;
}

int getElementOfDynamicArray(int *array, int length, int index)
{
  return array[index];
}

void deleteElementOfDynamicArray(int *&array, int &length, int index)
{
  for (int i = index; i < length - 1; i++)
  {
      array[i] = array[i + 1];
  }
  length -= 1;
  int* newArr = new int[length];
  for (int i = 0; i < length; i++)
  {
      newArr[i] = array[i];
  }
  delete[] array;
  array = newArr;
}

void copyFromListToDynamicArray(List *element, int *array, int *length)
{
  *length = lenOfList(element);
  for (int i = 0; i < *length; ++i)
  {
    array[i] = getElementOfListByIndex(element, i)->data;
  }
}

int main()
{
  bool finish = 1;
  List *list = createList(1);
  list->data = 0;
  int len = 1;
  int *arr = new int[len];
  *arr = 0;
  int choice1 = 0;
  while (finish)
  {
    printList(list);
    cout << "1. Заполнить список" << endl;
    cout << "2. Вставить в список" << endl;
    cout << "3. Удалить из списка" << endl;
    cout << "4. Обмен элементов списка" << endl;
    cout << "5. Получение элемента списка" << endl;
    cout << "6. Вывод списка и дин массива" << endl;
    cout << "9. Идз №9, чет -= число, нечет *= ранд(1,5)" << endl;
    int choice;
    choice = getNumber();
    switch (choice)
    {
      case 1: // заполнение
      {
        cout << "1. Заполнить список случайно" << endl;
        cout << "2. Ввести свои числа" << endl;
        choice1 = getNumber();
        switch (choice1)
        {
          case 1: // рандомно
          {
            cout << "Введите длину списка: ";
            int length;
            length = getNumber();
            list = createList(length);
            auto start = chrono::high_resolution_clock::now();
            fillListRandomly(list);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<float> duration = end - start;
            //
            cout << "Время заполнения списка:" << (duration.count() * 1000) << "(мс)" << endl;
            arr = createDynamicArray(length);
            start = chrono::high_resolution_clock::now();
            len = length;
            fillDynamicArrayRandomly(arr, length);
            end = chrono::high_resolution_clock::now();
            duration = end - start;
            cout << "Время заполнения дин массива:" << (duration.count() * 1000) << "(мс)" << endl;
            copyFromListToDynamicArray(list, arr, &len);
            break;
          }
          case 2: // пользовательски
          {
            cout << "Вводите числа, разделяя enter (чтобы закончить введите -1): " << endl;
            list = createList(1);
            auto start = chrono::high_resolution_clock::now();
            fillListUserly(list);
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<float> duration = end - start;
            cout << "Время заполнения:" << (duration.count() * 1000) << "(мс)" << endl;
            //
            start = chrono::high_resolution_clock::now();
            fillDynamicArrayUserly(arr, &len);
            end = chrono::high_resolution_clock::now();
            duration = end - start;
            cout << "Время заполнения дин массива:" << (duration.count() * 1000) << "(мс)" << endl;
            copyFromListToDynamicArray(list, arr, &len);
            break;
          }
          default:
          {
            cout << "неверный ввод" << endl;
          }
        }
        break;
      }
      case 2: // вставка
      {
        if (lenOfList(list) == 1 && list->data == 0)
          cout << "список пуст" << endl;
        else
        {
          cout << "Введите индекс для вставки: ";
          int index;
          index = getNumber();
          if (!correctIndex(index, lenOfList(list)))
          {
            cout << "Неверный индекс" << endl;
            break;
          }
          cout << "Введите число для вставки: ";
          int input;
          input = getNumber();
          auto start = chrono::high_resolution_clock::now();
          insertElementToSomePositionOfTheList(list, index, input);
          auto end = chrono::high_resolution_clock::now();
          chrono::duration<float> duration = end - start;
          // printList(list);
          cout << "Время вставки:" << (duration.count() * 1000) << "(мс)" << endl;
          start = chrono::high_resolution_clock::now();
          insertToDynamicArray(arr, len, index, input);
          end = chrono::high_resolution_clock::now();
          duration = end - start;
          // printList(list);
          cout << "Время вставки в дин массив:" << (duration.count() * 1000) << "(мс)" << endl;
        }
        break;
      }
      case 3: // удаление
      {
        if (lenOfList(list) == 1 && list->data == 0)
          cout << "список пуст" << endl;
        else
        {
          if (lenOfList(list) == 1 && getElementOfListByIndex(list, 0)-> data == 0)
          {
            cout << "Список пуст" << endl;
          }
          cout << "Введите индекс элемента для удаления: ";
          int index;
          index = getNumber();
          if (!correctIndex(index, lenOfList(list)))
          {
            cout << "Неверный индекс" << endl;
            break;
          }
          auto start = chrono::high_resolution_clock::now();
          if (index == 0 && lenOfList(list) == 1)
          {
            getElementOfListByIndex(list, 0)->data = 0;
          }
          else
          {
            list = deleteElementOfTheList(list, index);
          }
          auto end = chrono::high_resolution_clock::now();
          chrono::duration<float> duration = end - start;
          // printList(list);
          cout << "Время удаления:" << (duration.count() * 1000) << "(мс)" << endl;
          start = chrono::high_resolution_clock::now();
          if (index == 0 && len == 1)
          {
            arr[0] = 0;
          }
          else
          {
            deleteElementOfDynamicArray(arr, len, index);
          }
          end = chrono::high_resolution_clock::now();
          duration = end - start;
          // printList(list);
          cout << "Время удаления элемента дин массива:" << (duration.count() * 1000) << "(мс)" << endl;
        }
        break;
      }
      case 4: // обмен 
      {
        if (lenOfList(list) == 1 && list->data == 0)
          cout << "список пуст" << endl;
        else
        {
          cout << "Введите индексы элементов для обмена:";
          int index1, index2;
          index1 = getNumber();
          if (!correctIndex(index1, lenOfList(list)))
          {
            cout << "Неверный индекс" << endl;
            break;
          }
          index2 = getNumber();
          if (!correctIndex(index2, lenOfList(list)))
          {
            cout << "Неверный индекс" << endl;
            break;
          }
          auto start = chrono::high_resolution_clock::now();
          changeElementsOfTheList(list, index1, index2);
          auto end = chrono::high_resolution_clock::now();
          chrono::duration<float> duration = end - start;
          // printList(list);
          cout << "Время обмена:" << (duration.count() * 1000) << "(мс)" << endl;
          start = chrono::high_resolution_clock::now();
          changeElementsOfDynamicArray(arr, len, index1, index2);
          end = chrono::high_resolution_clock::now();
          duration = end - start;
          // printList(list);
          cout << "Время обмена элементов дин массива:" << (duration.count() * 1000) << "(мс)" << endl;
        }
        break;
      }
      case 5: // получение
      {
        if (lenOfList(list) == 1 && list->data == 0)
          cout << "список пуст" << endl;
        else
        {
          cout << "Введите индекс элемента получения:";
          int index;
          index = getNumber();
          if (!correctIndex(index, lenOfList(list)))
          {
            cout << "Неверный индекс" << endl;
            break;
          }
          auto start = chrono::high_resolution_clock::now();
          cout << getElementOfListByIndex(list, index)->data << endl;
          auto end = chrono::high_resolution_clock::now();
          chrono::duration<float> duration = end - start;
          // printList(list);
          cout << "Время получения:" << (duration.count() * 1000) << "(мс)" << endl;
          start = chrono::high_resolution_clock::now();
          cout << getElementOfDynamicArray(arr, len, index) << endl;
          end = chrono::high_resolution_clock::now();
          duration = end - start;
          // printList(list);
          cout << "Время получения элемента дин массива:" << (duration.count() * 1000) << "(мс)" << endl;
        }
        break;
      }
      case 6:
      {
        cout << "Список: ";
        printList(list);
        cout << "Дин массив: ";
        printDynamicArray(arr, len);
        break;
      }
      case 9:
      {
        cout << "Число пользователя:";
        int number;
        number = getNumber();
        int randInt = rand() % 5 + 1;
        cout << "Случайное число:" << randInt << endl;
        auto start = chrono::high_resolution_clock::now();
        for (int i = 1; i < lenOfList(list); i += 2)
        {
          getElementOfListByIndex(list, i)->data -= number; 
        }
        for (int i = 0; i < lenOfList(list); i += 2)
        {
          getElementOfListByIndex(list, i)->data *= randInt;
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<float> duration = end - start;
        cout << "Время изменения списка:" << (duration.count() * 1000) << "(мс)" << endl;
        //
        start = chrono::high_resolution_clock::now();
        for (int i = 1; i < lenOfList(list); i += 2)
        {
          arr[i] -= number; 
        }
        for (int i = 0; i < lenOfList(list); i += 2)
        {
          arr[i] *= randInt;
        }
        end = chrono::high_resolution_clock::now();
        duration = end - start;
        //
        cout << "Время изменения дин массива:" << (duration.count() * 1000) << "(мс)" << endl;
        break;
      }
      default:
      {
        cout << "Неверно выбран пункт меню" << endl;
      }
    }
  }
  srand(time(0));
  auto start = chrono::high_resolution_clock::now();
  List *l = createList(5);
  fillListRandomly(l);
  printList(l);
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<float> duration = end - start;
  cout << "Время создания:" << (duration.count() * 1000) << "(мс)" << endl;
  return 0;
}
