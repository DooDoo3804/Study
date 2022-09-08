from django import forms
from .models import Article

class ArticleForm(forms.ModelForm):
    # title = forms.CharField(max_length=10)
    # content = forms.CharField(widget=forms.Textarea)
    # CLASS_A = 's1'
    # CLASS_B = 's2'
    # CLASS_C = 's3'
    # CLASS_D = 's4'
    # CLASS_E = 's5'
    # CLASS_F = 's6'
    # CLASS_CHOICES = [
    #     (CLASS_A, '1반'),
    #     (CLASS_B, '2반'),
    #     (CLASS_C, '3반'),
    #     (CLASS_D, '4반'),
    #     (CLASS_E, '5반'),
    #     (CLASS_F, '6반'),
    # ]
    # ssafyclass = forms.ChoiceField(choices = CLASS_CHOICES)
    class Meta:
        model = Article
        # fields = '__all__'
        exclude = ('ssafyclass')
