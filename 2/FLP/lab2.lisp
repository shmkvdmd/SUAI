(defun sortin (lst)
  (cond ((null lst)
         nil)
        (t
         (insert (car lst) (sortin (cdr lst))))))

(defun insert (elem lst)
  (cond ((null lst)
         (cons elem nil))
        ((<= elem (car lst))
         (cons elem lst))
        (t
         (cons (car lst) (insert elem (cdr lst))))))

(print '(9 8 7 6 5 4 3 2 1))
(print (sortin '(9 8 7 6 5 4 3 2 1)))
