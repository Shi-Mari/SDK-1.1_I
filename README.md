# Имитатор гирлянды с переключением режимов <br> 

## Задание

Разработать и реализовать драйверы управления светодиодными индикаторами и чтения состояния кнопки стенда SDK-1.1М (на базе stm32). Контакты подключения кнопки и светодиодов должны быть настроены в режиме GPIO. Функции и другие компоненты драйверов должны быть универсальными, т.е. пригодными для использования в любом из вариантов задания и не должны содержать прикладной логики программы. Функции драйверов должны быть неблокирующими, то есть не должны содержать ожиданий события. Также, в драйверах не должно быть пауз с активным ожиданием. Обработка нажатия кнопки в программе должна включать программную защиту от дребезга. 


## Результаты работы

Реализован имитатор гирлянды с переключением режимов.Режимы представляют собой четыре последовательности переключения светодиодов с разной частотой мигания. В каждом режиме задействуется не менее двух светодиодов. По нажатию кнопки происходит циклическое переключение режимов. При повторном входе в какой-либо режим анимация на светодиодах запускается с того места, на котором в прошлый раз была прервана переключением на следующий режим. Удерживание зажатой кнопки не приводить к «повисанию» анимации.

В функции main ([main.c](main.c)) перед циклом while(1) настраиваем систему тактирования; настраиваем порт кнопки: тактируем задаем на вход; настраиваем порты светодиодов на выход; настраиваем таймеры 2 и 3. 
Таймер 2 используем для переключения светодиодов, таймер 3 – для борьбы с дребезгом кнопки. В цикле while(1) реализована работа с кнопкой, ожидание отжатия и нажатия для борьбы с дребезгом. В функции обработчика прерываний таймера 2 вызывается функция включения/выключения светодиодов. Функция включения выключения светодиодов в зависимости от последовательности в каждом режиме моргания реализована с помощью оператора switch – case.  
В файле [main.h](main.h)  находятся постоянные для регулирования частоты моргания, вспомогательные переменные и массивы для работы режимов и т. д.
В файле [regmap.h](regmap.h) записаны адреса регистров контроллера.
Платформа разработки - CubeIDE, контроллер - STM32F427VI.
