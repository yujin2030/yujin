   M S B A M L   `   `   `  ����S  O1028 (데이터바인딩, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullE'clr-namespace:_1028__데이터바인딩_1028__데이터바인딩  5   	   *    $_1028__데이터바인딩.MainWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   9local'clr-namespace:_1028__데이터바인딩     5   	     � Title$  
MainWindow��5   	   $	��450��6   $	��800��6)   .��5	      �� .+�5
   
   �  � ColumnDefinitions 5      �� 5      �� 5      �� 5      .+�5      �� $��0��6   $��5q�6)    �� Orientation$ 
Horizontal=�64   .+�5      �� .��6   이름(_N):6!   �� 5      -   5        $
��name��5      $	��120��6&   5      �� 5      $��1��6   $��5q�6)   $ 
Horizontal=�64   .+�5      �� .��6   전화(_P):6!   �� 5      -   5        $��phone��5      $	��120��6'   5      �� 5      $��2��6   $��5q�6)   $ 
Horizontal=�64   .+�5      �� .��6   나이(_A):6!   �� 5      -   5        $	��age��5      $	��120��6%   5      5      � 5   
    5      �� 5      �� 5       �� 5!      .+�5#      �� $��0��6   $��2q�6%   
���   �$��2q�6D   ._�5$      �� -   5        $��	nameLabel��5$   $   $��25��6   6$   5%      �� 5&      $��1��6   $��2q�6%   
���   �$��2q�6D   ._�5'      �� -   5        $��
phoneLabel��5'   $   $��25��6   6$   5(      �� 5)      $��2��6   $��2q�6%   
���   �$��2q�6D   ._�5*      �� -   5        $��ageLabel��5*   $   $��25��6   6$   5+      5,      � 5-   
    5.      �� 5/      �� 50      �� 51      .+�53      �� -   5        $��	addButton��53      $��3q�6&   $��30��61   $��0��6=   $��추가��6M   6Z   �� 54      -   5        $��removeButton��54      $��3q�6)   $��30��64   $��1��6@   $��삭제��6P   6]   �� 55      -	   5        $��updateButton��55      $��3q�6)   $��30��64   $��2��6@   $��수정��6P   6]   56      �� 57   
   -
   5        $��listbox��57      6"   59      5;      