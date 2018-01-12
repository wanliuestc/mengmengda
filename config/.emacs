(add-hook 'after-init-hook 'global-company-mode)
(setq python-shell-interpreter "python3")
(setq make-backup-files nil)
(setq auto-save-default nil)
(add-hook 'c-mode-hook	 
	  (lambda()
	    (c-set-style "k&r")))
(add-hook 'c++-mode-hook	 
	  (lambda()
	    (c-set-style "ellemtel")))

(require 'package)
(add-to-list 'package-archives
	     '("elpy" . "https://jorgenschaefer.github.io/packages/"))

(add-to-list 'load-path "/root/.emacs.d/elpa/org-9.1.2/lisp")
(add-to-list 'load-path "/root/.emacs.d/elpa/org-9.1.2/contrib/lisp" t)

(global-linum-mode t)  
(column-number-mode t) 
