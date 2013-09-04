set backspace=indent,eol,start

"Syntax highlighting do faiska"
au BufRead,BufNewFile *.fsk set filetype=faiska
syntax on
au! Syntax faiska source $HOME/.vim/syntax/fsk.vim
au! Syntax faiska source $HOME/.vim/syntax/armasm.vim
let asmsyntax='armasm' 
let filetype_inc='armasm'

"Syntax highlighting do archc"
au BufRead,BufNewFile *.ac set filetype=archc
syntax on
au! Syntax archc source $HOME/.vim/syntax/archc.vim

"Geral"
set autoindent
set number
set pastetoggle=<F2>
set cindent
:filetype on

"Para o python"
autocmd BufRead *.py set smartindent cinwords=if,elif,else,for,while,try,except,finally,def,class
autocmd BufRead *.py im :<CR> :<CR><TAB>


set nocompatible               " be iMproved
filetype off                   " required!


filetype plugin indent on     " required!

set tabstop=4
set shiftwidth=4
set expandtab

let g:clang_library_path="/usr/lib64/llvm/"
