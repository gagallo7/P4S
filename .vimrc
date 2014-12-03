"Geral"
set number
set pastetoggle=<F2>
:filetype on

set backspace=indent,eol,start

"Syntax highlighting do faiska"
au BufRead,BufNewFile *.fsk set filetype=faiska
syntax on
au! Syntax faiska source $HOME/.vim/syntax/fsk.vim
au! Syntax faiska source $HOME/.vim/syntax/armasm.vim
let asmsyntax='armasm' 
let filetype_inc='armasm'

au BufRead,BufNewFile *.npl set filetype=npl
syntax on
au! Syntax npl source $HOME/.vim/syntax/npl.vim

au BufRead,BufNewFile *.mod set filetype=gmpl
syntax on
au! Syntax gmpl source $HOME/.vim/syntax/gmpl.vim

"Syntax highlighting do archc"
au BufRead,BufNewFile *.ac set filetype=archc
au! Syntax archc source $HOME/.vim/syntax/archc.vim

"Syntax highlighting do OpenCL"
au BufRead,BufNewFile *.cl set filetype=opencl
au! Syntax opencl source $HOME/.vim/syntax/opencl.vim

"Para o python"
autocmd BufRead *.py set smartindent cinwords=if,elif,else,for,while,try,except,finally,def,class
autocmd BufRead *.py im :<CR> :<CR><TAB>


set nocompatible               " be iMproved
filetype off                   " required!


filetype plugin indent on     " required!

set expandtab
set tabstop=4
set shiftwidth=4
set autoindent
set cindent

set encoding=utf-8
set scrolloff=3
set showmode
set showcmd
set hidden
set wildmenu
set wildmode=list:longest
set visualbell
set cursorline
set ttyfast
set ruler
set laststatus=2
set relativenumber
set undofile

nnoremap <up> <nop>
nnoremap <down> <nop>
nnoremap <left> <nop>
nnoremap <right> <nop>
inoremap <up> <nop> inoremap <down> <nop>
inoremap <left> <nop>
inoremap <right> <nop>
nnoremap j gj
nnoremap k gk

execute pathogen#infect()
syntax enable
nmap <F8> :TagbarToggle<CR>
"imap . .<C-x><C-u>
let g:solarized_termcolors=256
autocmd BufRead *.py nnoremap <F4> :w <bar> exec '!python '.shellescape('%')<CR>
autocmd BufRead *.c <F4> :w <bar> exec '!gcc '.shellescape('%').' -o '.shellescape('%:r').' && ./'.shellescape('%:r')<CR>
"autocmd BufRead *.cpp nnoremap <F4> :w <bar> exec '!g++ -Wall -Werror -std=c++11 '.shellescape('%').' -o '.shellescape('%:r').' && ./'.shellescape('%:r')<CR>
"autocmd BufRead *.cpp nnoremap <F5> :w <bar> exec '!gfilt -Wall -Werror -std=c++11 '.shellescape('%').' -o '.shellescape('%:r').' && ./'.shellescape('%:r')<CR>
autocmd Filetype cpp nmap <buffer> <F9> :SCCompileAF -Wall -Werror -std=c++11 <CR>
autocmd Filetype cpp nmap <buffer> <F10> :SCCompileRunAF -Wall -Werror -std=c++11 <CR>
autocmd Filetype cpp nnoremap <silent> <buffer> <cr> :CSearchContext<cr>

au BufRead,BufNewFile *.tem set filetype=cpp

let g:EclimCompletionMethod = 'omnifunc'

function FileHeading()
    let s:line=line(".")
    call setline(s:line,"/*********************************************")
    call append(s:line,"* Description - ")
    call append(s:line+1,"* Author - Guilherme Alcarde Gallo")
    call append(s:line+2,"* Date - ".strftime("%b %d %Y"))
    call append(s:line+3,"* *******************************************/")
    unlet s:line
endfunction

imap <F4> <Esc>mz:execute FileHeading()<cr>`zjA
