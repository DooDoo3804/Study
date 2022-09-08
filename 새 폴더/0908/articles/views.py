from django.shortcuts import render, redirect
from articles.forms import ArticleForm
from articles.models import Articles

# Create your views here.
def index(request):
    articles = Articles.objects.all()
    context = {
        'articles' : articles
    }
    return render(request, 'articles/index.html', context)

def create(request):
    if request.method == "POST":
        form = ArticleForm(request.POST)
        if form.is_valid():
            article = form.save()
            return redirect("articles:detail", article.pk)
    else:
        form = ArticleForm()
    context = {
        'form' : form
    }
    return render(request, 'articles/create.html', context)


def update(request, pk):
    articles = Articles.objects.get(pk=pk)
    if request.method == "POST":
        form = ArticleForm(request.POST, instance=articles)
        if form.is_valid():
            article = form.save()
            return redirect("articles:detail", article.pk)
    else:
        form = ArticleForm(instance=articles)
    context = {
        'form' : form,
        'articles' : articles
    }
    return render(request, "articles/update.html", context)

def detail(request, pk):
    articles = Articles.objects.get(pk=pk)
    context = {
        'articles' : articles
    }
    return render(request, "articles/detail.html", context)