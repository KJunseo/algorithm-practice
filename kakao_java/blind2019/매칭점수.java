package blind2019;

import java.util.ArrayList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class 매칭점수 {
    private static final Pattern urlPattern = Pattern.compile("<meta property=\"og:url\" content=\\S+/>");
    private static final Pattern eternalLink = Pattern.compile("<a href=\\S+>");

    private List<Page> list;

    public int solution(String word, String[] pages) {
        list = new ArrayList<>();

        word = word.toLowerCase();

        int id = 0;
        for (String html : pages) {
            String lowerPage = html.toLowerCase();

            Matcher urlMatcher = urlPattern.matcher(lowerPage);
            String url = "";
            if (urlMatcher.find()) {
                url = urlMatcher.group();
                url = url.substring(33);
                url = url.substring(0, url.length() - 3);
            }

            list.add(new Page(id++, url, countContain(lowerPage, word), getLinks(lowerPage)));
        }

        for (Page page : list) {
            for (Page compare : list) {
                if (page.id == compare.id) {
                    continue;
                }

                if (compare.contain(page.url)) {
                    page.linkScore += (double) compare.basicScore / compare.externalLinks.size();
                }
            }

            page.matchingScore = page.basicScore + page.linkScore;
        }

        list.sort((a, b) -> {
            if (a.matchingScore == b.matchingScore) {
                return a.id - b.id;
            }
            if (a.matchingScore < b.matchingScore) {
                return 1;
            } else {
                return -1;
            }
        });

        return list.get(0).id;
    }

    private List<String> getLinks(String page) {
        List<String> links = new ArrayList<>();
        Matcher matcher = eternalLink.matcher(page);

        while (matcher.find()) {
            String link = matcher.group();
            link = link.substring(9);
            link = link.substring(0, link.length() - 6);
            links.add(link);
        }

        return links;
    }

    private int countContain(String page, String word) {
        int count = 0;
        String[] temp = page.split("[^a-z]");
        for (String s : temp) {
            if (s.equals(word)) {
                count++;
            }
        }
        return count;
    }

    static class Page {
        int id;
        String url;
        int basicScore;
        List<String> externalLinks;
        double linkScore;
        double matchingScore;

        public Page(int id, String url, int basicScore, List<String> links) {
            this.id = id;
            this.url = url;
            this.basicScore = basicScore;
            this.externalLinks = links;
        }

        public boolean contain(String url) {
            return externalLinks.contains(url);
        }
    }
}
