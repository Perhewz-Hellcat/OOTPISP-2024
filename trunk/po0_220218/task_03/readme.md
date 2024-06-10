# Лабораторная работа №2 #

## Правила перегрузки операций и принципы обработки исключений в С++ ##

## Вариант 4 ##

## Цель работы ##

Изучить правила перегрузки операций и принцивы обработки исключений в С++

### Обработка исключаний для Container \*operator [](const int index) ###

```c++
    
IError *Container::operator[](const int index)
{
    try
    {
        if (index < 0 || index >= _size)
            throw std::out_of_range("index out of range");

        auto ptr = std::move(head);
        for (int i = 0; i < index; i++)
        {
            ptr = std::move(ptr->next);
        }
        return ptr->date;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << e.what() << std::endl;
        IError err;
        return nullptr;
    }
}
```

## Перегрузка операторов ##

### Class NotEnoughMemory ###

```c++
bool NotEnoughMemory::operator==(const NotEnoughMemory &right) const
{
    return (this->memType == right.memType);
}

```

### Class IOError ###

```c++
bool IOError::operator==(const IOError &right) const
{
    return (this->error == right.error);
}
```

### Class ReadFileError ###

```c++

bool ReadFileError::operator==(const ReadFileError &right) const
{
    return (this->errorCode == right.errorCode);
}

```

### Class WriteFileError ###

```c++
bool WriteFileError::operator==(const WriteFileError &right) const
{
    return (this->writeError == right.writeError);
}

```

