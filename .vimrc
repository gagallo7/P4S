"Geral"
set number
set pastetoggle=<F2>
:filetype on

set backspace=indent,eol,start

"Syntax highlighting do faiska"
syntax on

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
"
"Syntax highlighting TeX°
au BufRead,BufNewFile *.tex set spell

"Para o python"
autocmd BufRead *.py set smartindent cinwords=if,elif,else,for,while,try,except,finally,def,class
autocmd BufRead *.py im :<CR> :<CR><TAB>


set nocompatible               " be iMproved
filetype off                   " required!

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo
"

" Example plugin
Plugin 'tpope/vim-fugitive'
Plugin 'tpope/vim-surround'
Plugin 'easymotion/vim-easymotion'
Plugin 'kshenoy/vim-signature'
" plugin from http://vim-scripts.org/vim/scripts.html
Plugin 'L9'
" Git plugin not hosted on GitHub
"Plugin 'git://git.wincent.com/command-t.git'
" git repos on your local machine (i.e. when working on your own plugin)
" Plugin 'file:///home/gmarik/path/to/plugin'
" The sparkup vim script is in a subdirectory of this repo called vim.
" Pass the path to set the runtimepath properly.
"Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" Avoid a name conflict with L9
" Plugin 'user/L9', {'name': 'newL9'}
"
" Processing

Plugin 'sophacles/vim-processing'
Plugin 'Dinduks/vim-java-get-set'
"
" Favorite Plugins
Plugin 'majutsushi/tagbar'
Plugin 'tpope/vim-sensible'
Plugin 'tpope/vim-obsession'
Plugin 'dhruvasagar/vim-procession'
Plugin 'airblade/vim-gitgutter'
Plugin 'xuhdev/SingleCompile'
Plugin 'Valloric/YouCompleteMe'
Plugin 'rdnetto/YCM-Generator'
Plugin 'vim-airline/vim-airline'

Plugin 'jalcine/cmake.vim'

"filesystem
Plugin 'scrooloose/nerdcommenter'
Plugin 'scrooloose/nerdtree'
Plugin 'jistr/vim-nerdtree-tabs'
Plugin 'Xuyuanp/nerdtree-git-plugin'
Plugin 'ctrlpvim/ctrlp.vim'
"
"html
Plugin 'isnowfy/python-vim-instant-markdown'
Plugin 'jtratner/vim-flavored-markdown'
Plugin 'suan/vim-instant-markdown'
Plugin 'hail2u/vim-css3-syntax'
Plugin 'gorodinskiy/vim-coloresque'
Plugin 'tpope/vim-haml'
"Plugin 'mattn/emmet-vim'
Plugin 'scrooloose/syntastic'

"Colors!!!
Plugin 'altercation/vim-colors-solarized'
Plugin 'jnurmine/Zenburn'

" Laravel
Plugin 'xsbeats/vim-blade'
Bundle 'chrisgillis/vim-bootstrap3-snippets'
Plugin 'xolox/vim-misc'
Plugin 'StanAngeloff/php.vim' 
Plugin 'arnaud-lb/vim-php-namespace'

" Track the engine.
"Plugin 'MarcWeber/vim-addon-mw-utils'
"Plugin 'tomtom/tlib_vim'
"Plugin 'garbas/vim-snipmate'
Plugin 'SirVer/ultisnips'

" Snippets are separated from the engine. Add this if you want them:
Plugin 'honza/vim-snippets'
Plugin 'sheerun/vim-polyglot'

" LaTex
" Plugin 'lervag/vimtex'
Plugin 'vim-latex/vim-latex'
Plugin 'beloglazov/vim-online-thesaurus'
Plugin 'maksimr/vim-translator' 

"Plugin 'rbonvall/snipmate-snippets-bib'


" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line

let g:tex_flavor='latex'
set <m-i>=i
set <m-b>=b
set <m-c>=c
set <m-l>=l

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
let g:solarized_termcolors=256
syntax enable
set background=dark
colorscheme solarized
nmap <F8> :TagbarToggle<CR>
nmap <C-n> :NERDTreeToggle<CR>
"imap . .<C-x><C-u>
"autocmd BufRead *.py nnoremap <F4> :w <bar> exec '!python '.shellescape('%')<CR>
"autocmd BufRead *.c <F4> :w <bar> exec '!gcc '.shellescape('%').' -o '.shellescape('%:r').' && ./'.shellescape('%:r')<CR>
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

let maplocalleader = ","
imap <F4> <Esc>mz:execute FileHeading()<cr>`zjA
nnoremap <F12> :OnlineThesaurusCurrentWord<CR>
nnoremap zy :OnlineThesaurusCurrentWord<CR><C-W><C-K>
vnoremap <unique> <LocalLeader>k y:Thesaurus <C-r>"<CR>
nnoremap <unique> <LocalLeader> yiw :tag <C-r>"<CR>
xnoremap <unique> <LocalLeader>R :s#<C-r>"#
nnoremap <unique> <LocalLeader>R yiw :%s#<C-r>"#

" Column highlighting
set cc=80

"
" Latex PDF
let g:Tex_DefaultTargetFormat='pdf'
let g:Tex_CompileRule_pdf='pdflatex -interaction=nonstopmode -file-line-error --synctex=1 $*'

function CompileXeTex()
    let oldCompileRule=g:Tex_CompileRule_pdf
    let g:Tex_CompileRule_pdf = 'xelatex -aux-directory=/tmp --synctex=-1 -src-specials -interaction=nonstopmode $*'
    call Tex_RunLaTeX()
    let g:Tex_CompileRule_pdf=oldCompileRule
endfunction
map <Leader>lx :<C-U>call CompileXeTex()<CR>

function! SyncTexForward()
    let s:syncfile = fnamemodify(fnameescape(Tex_GetMainFileName()), ":r").".pdf"
    echo s:syncfile
    let execstr = "silent! !okular --unique ".s:syncfile."\\#src:".line(".").expand("%\:p").' &'
    exec execstr
endfunction
nnoremap -f :call SyncTexForward()<CR><C-L>

let g:Tex_DefaultTargetFormat = 'pdf'
let g:Tex_MultipleCompileFormats = 'pdf'

" Trigger configuration. Do not use <tab> if you use https://github.com/Valloric/YouCompleteMe.
let g:UltiSnipsExpandTrigger="<C-Space>"
"let g:UltiSnipsJumpForwardTrigger="<c-b>"
"let g:UltiSnipsJumpBackwardTrigger="<c-z>"

" If you want :UltiSnipsEdit to split your window.
let g:UltiSnipsEditSplit="vertical"

augroup markdown
    au!
    au BufNewFile,BufRead *.md,*.markdown setlocal filetype=ghmarkdown
augroup END

"" NERDTree configuration
let g:NERDTreeChDirMode=2
let g:NERDTreeIgnore=['\.aux$', '\.blg$', '\.dvi', '\.log$', '\.rbc$', '\~$', '\.pyc$', '\.db$', '\.sqlite$', '__pycache__']
let g:NERDTreeSortOrder=['\.bib$', '\.tex$', '^__\.py$', '\/$', '*', '\.swp$', '\.bak$', '\~$']
let g:NERDTreeShowBookmarks=1
let g:nerdtree_tabs_focus_on_files=1
let g:NERDTreeMapOpenInTabSilent = '<RightMouse>'
let g:NERDTreeWinSize = 50
set wildignore+=*/tmp/*,*.so,*.swp,*.zip,*.pyc,*.db,*.sqlite
nnoremap <silent> <F2> :NERDTreeFind<CR>
noremap <F3> :NERDTreeToggle<CR>

" ViM PHP
" Put at the very end of your .vimrc file.
function! PhpSyntaxOverride()
    hi! def link phpDocTags  phpDefine
    hi! def link phpDocParam phpType
endfunction

augroup phpSyntaxOverride
    autocmd!
    autocmd FileType php call PhpSyntaxOverride()
augroup END

" Non ascii chars highlighting
syntax match nonascii "[^\x00-\x7F]"
highlight nonascii guibg=Red ctermbg=2
