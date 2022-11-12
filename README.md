# qtlib-toastr
___Библиотека для отображения всплывающих подсказок___
***
## _Methods_
* ___setText (QString text)___ - устанавливает текст подсказки
* ___setDuration (uint msec)___ - задаёт продолжительность подсказки
* ___setShowDuration (uint msec)___ - задаёт продолжительность анимации появления подсказки
* ___setHideDuration (uint msec)___ - задаёт продолжительность анимации скрытия подсказки
* ___setTextColor (QString color)___ - задаёт цвет текста ('<span style="color:red">#ff0000'</span>)
* ___setBackgroundColor (QString color)___ - задаёт цвет фона подсказки ('<span style="color:blue">#0000ff'</span>)
* ___setOpacity (uint opacity)___ - устанавливает прозрачность фона (opacity: 0 - 255)
* ___setIcon (QPixmap pixmap)___ - устанавливает иконку
* ___setStyle (TOASTR_STYLE style)___ - устанавливает стиль подсказки (см. Style)
* ___setOrientation (TOASTR_ORIENTATION orientation)___ - устанавливает позицию подсказки (см. Orientation)
***
## _Style_
* ___MESSAGE___
![Message](Screenshots/MESSAGE.JPG)
* ___SUCCESS___
![Message](Screenshots/SUCCESS.JPG)
* ___INFO___
![Message](Screenshots/INFO.JPG)
* ___WARNING___
![Message](Screenshots/WARNING.JPG)
* ___FAIL___
![Message](Screenshots/FAIL.JPG)
***
## _Orientation_
* ___TOP_RIGHT___
* ___TOP_LEFT___
* ___TOP_CENTER___
* ___TOP_FULL_WIDTH___
* ___BOTTOM_RIGHT___
* ___BOTTOM_LEFT___
* ___BOTTOM_CENTER___
* ___BOTTOM_FULL_WIDTH___
***
## _Example_
```
Toastr* toastr = new Toastr();
toastr->setStyle(Toastr::TOASTR_STYLE::WARNING);
toastr->setText("Запись прервана!");
toastr->setDuration(3000);
toastr->show();
```