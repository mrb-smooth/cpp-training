" Author:  Malik R. Booker
" Updated: December 1, 2021

" This is a heavily modified version that operates with base vim

" Interpreter
:let g:python3_host_prog='/usr/bin/env python3'

" Plugins
:filetype plugin indent on

" Auto-completion
:silent! inoremap {<CR> {<cr>}<esc>ko

" Bindings
:silent! noremap <Right> <Nop>
:silent! noremap <Down>  <Nop>
:silent! noremap <Left>  <Nop>
:silent! noremap <Up>    <Nop>
:silent! nnoremap ` gt<CR>
:silent! nnoremap ~ gT<CR>

" Settings
:set backspace=indent,eol,start
:set clipboard=unnamedplus
:set colorcolumn=80
:set encoding=utf-8
:set showtabline=2
:set softtabstop=4
:set termguicolors
:set shiftwidth=4
:set nocompatible
:set splitbelow
:set splitright
:set noswapfile
:set tabstop=4
:set expandtab
:set wildmenu
:set path+=**
:set mouse=a
:set number
:set secure
:set hidden
:set nowrap
:set spell
:set go+=a
:set exrc

" Appearance
:syntax enable
:set background=light

" Styling -> 4 spaces
:autocmd filetype c          setlocal tabstop=4 shiftwidth=4 softtabstop=4
:autocmd filetype cpp        setlocal tabstop=4 shiftwidth=4 softtabstop=4
:autocmd filetype java       setlocal tabstop=4 shiftwidth=4 softtabstop=4
:autocmd filetype csharp     setlocal tabstop=4 shiftwidth=4 softtabstop=4

" Styling -> 2 spaces
:autocmd filetype css        setlocal tabstop=4 shiftwidth=2 softtabstop=2
:autocmd filetype html       setlocal tabstop=4 shiftwidth=2 softtabstop=2
:autocmd filetype javascript setlocal tabstop=4 shiftwidth=2 softtabstop=2
