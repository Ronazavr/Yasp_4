Общее условие:
Написать программу, содержащую следующие функции:
− Две функции заполнения текстового файла N целыми случайными числами
в диапазоне от -M до M. Имя файла, N и M поступают на вход функциям, готовый
к работе файл возвращается функциями как результат (использовать потоки
ввода-вывода). Реализовать два варианта генерации чисел — в цикле
и с использованием алгоритма std::generate (generate_n);
− Метод, получающий файловый поток на вход, которая осуществляет чтение чисел
из файла в последовательный контейнер;
− Три версии метода modify, выполняющей преобразование контейнера. На вход
функции должны поступать итераторы начала и конца обрабатываемой части
контейнера, в качестве результата функция должна возвращать
модифицированный контейнер (не изменяя исходный). Реализовать алгоритм
через: for, std::transform, std::for_each;
− Методы, вычисляющие сумму и среднее арифметическое чисел, содержащихся
в контейнере (не вычислять вручную через явный вызов for/while/do-while);
− Метод потокового вывода результата. Осуществить вывод в файл и на экран с ее
помощью.
N, M, K1, K2 вводятся пользователем.

5. Заменить каждое число на корень из суммы квадрата текущего числа
и квадрата первого числа. Ответ округлить до целых
