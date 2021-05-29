#lang racket
(provide main)
(require "parse.rkt" "compile.rkt" "mparse.rkt" a86/printer)

;; main: String -> Void
;; So, in summary:
;; 1. String -> S-exps (Reader)
;; 2. S-exps -> AST (parse)
;; 3. AST -> x86 AST (compile)
;; 4. x86 AST -> NASM (asm-string)
(define (main filename)
  (let ([filename-port (open-input-file filename)])
    (begin
      (displayln
       (asm-string
        (compile
         (parse
          (mread (port->string filename-port) filename)))))
      (close-input-port filename-port))))