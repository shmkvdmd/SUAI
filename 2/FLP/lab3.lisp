(defun next-v (graph v sppv) 
  (let ((nest (assoc v graph))) 
    (if nest 
        (let ((rest (cdr nest))) 
          (remove-if #'(lambda (x) (member x sppv)) rest)) 
        nil)))

(defun enum-spv2 (g v1 v2 &optional (spv (list v1)))
  (if (eql v1 v2) 
      (list spv) 
      (let ((c-n (next-v g v1 spv))) 
        (if c-n 
            (apply #'append 
                   (mapcar #'(lambda (x) 
                               (enum-spv2 g x v2 (append spv (list x)))) c-n))
            nil)))) 

(defun count-posver (g v1 v2)
  (length (enum-spv2 g v1 v2)))

 (defun connectivity-degree (graph)
  (let* ((versh (mapcar #'car graph)) 
         (paths (remove nil 
                        (mapcar #'(lambda (v1) 
                                    (remove nil 
                                           (mapcar #'(lambda (v2)
                                                       (when (not (eql v1 v2)) 
                                                         (count-posver graph v1 v2))) 
                                                   versh))) 
                                versh)))) 
    (if paths
        (reduce #'min (apply #'append paths)) 
        0))) 

(setq graph '((A B D)(B A C D)(C B E)(D A B E)(E C D)))

(print(connectivity-degree graph))
