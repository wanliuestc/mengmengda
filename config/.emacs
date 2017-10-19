(add-hook 'after-init-hook 'global-company-mode)
(setq make-backup-files nil)
(add-hook 'c-mode-hook
	  (lambda()
	    (c-set-style "k&r")))
