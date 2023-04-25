;Определение переменных
(defvar *repertoire* nil)
(defvar *genres* '(drama comedy tragedy musical))

;Функция для добавления спектакля в репертуар
(defun add-play (title genre duration price)
  (let ((play (list :title title :genre genre :duration duration :price price)))
    (setf *repertoire* (cons play *repertoire*))))

;Функция для удаления спектакля из репертуара
(defun remove-play (title)
  (setf *repertoire* (remove-if (lambda (play) (equal (getf play :title) title)) *repertoire*)))
  
;Функция для замены данных спектакля
(defun update-play (title field value)
  (dolist (play *repertoire*)
    (when (equal (getf play :title) title)
      (setf (getf play field) value))))

;Функция для поиска спектаклей по жанру
(defun find-plays-by-genre (genre)
  (remove-if-not (lambda (play) (equal (getf play :genre) genre)) *repertoire*))
  
;Функция для поиска спектакля по названию
(defun find-play-by-title (title)
  (find-if (lambda (play) (equal (getf play :title) title)) *repertoire*))
 
 ; Функция для поиска спектаклей по частичному совпадению названия
(defun find-plays-by-title-partial (partial-title)
  (remove-if-not (lambda (play)
                   (let ((title (getf play :title)))
                     (and (stringp title)
                          (search partial-title title))))
                 *repertoire*))

;Функция для поиска спектаклей с продолжительностью не более указанной
(defun find-plays-by-duration (duration)
  (remove-if-not (lambda (play) (<= (getf play :duration) duration)) *repertoire*))
  
; Функция для поиска самого дешевого спектакля
(defun find-cheapest-play ()
  (reduce (lambda (p1 p2) (if (< (getf p1 :price) (getf p2 :price)) p1 p2)) *repertoire*))
  
; Функция для поиска самого дорогого спектакля
(defun find-expensive-play ()
  (reduce (lambda (p1 p2) (if (> (getf p1 :price) (getf p2 :price)) p1 p2)) *repertoire*))
