from django.http import HttpResponseRedirect
from django.core.urlresolvers import reverse
from django.shortcuts import render, get_object_or_404
from django.views import generic
from django.utils import timezone
from poll.models import Poll, Choice


class IndexView(generic.ListView):
    template_name = 'poll/index.html'
    context_object_name = 'latest_poll_list'

    def get_queryset(self):
        return Poll.objects.filter(pub_date__lte=timezone.now()).order_by('pub_date')[:5]


class DetailView(generic.DetailView):
    model = Poll
    template_name = 'poll/detail.html'


class ResultView(generic.DetailView):
    model = Poll
    template_name = 'poll/result.html'


def vote(request, poll_id):
    p = get_object_or_404(Poll, pk=poll_id)
    try:
        selected_choice = p.choice_set.get(pk=request.POST['choice'])
    except (KeyError, Choice.DoesNotExist):
        pass
        return render(request, 'poll/detail.html', {
            'poll': p,
            'error_message': "You didn't select a choice.",
        })
    else:
        selected_choice.votes += 1
        selected_choice.save()
        return HttpResponseRedirect(reverse('poll:result', args=(p.id,)))

# def index(request):
#     latest_poll_list = Poll.objects.order_by('pub_date')[:5]
#     context = {'latest_poll_list': latest_poll_list}
#     return render(request, 'poll/index.html', context)
#
# def detail(request, poll_id):
#     poll = get_object_or_404(Poll, pk=poll_id)
#     return render(request, 'poll/detail.html', {'poll': poll})
#
# def result(request, poll_id):
#     poll = get_object_or_404(Poll, pk=poll_id)
#     return render(request, 'poll/result.html', {'poll': poll})
#
