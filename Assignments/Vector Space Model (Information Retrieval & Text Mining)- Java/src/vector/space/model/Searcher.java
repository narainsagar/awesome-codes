/*
....................... ASSIGNMENT NO # 02 ............................
....................... NAME : NARAIN SAGAR ............................
....................... COURSE : INFORMATION RETRIEVAL .................
....................... INSTRUCTOR : M. RAFI ............................
 */
package vector.space.model;

import java.io .File;
import java.io .IOException; 
import java.io.StringReader;
import org.apache.lucene.analysis.PorterStemFilter;
import org.apache.lucene.analysis.TokenStream;
import org.apache.lucene .analysis.standard.StandardAnalyzer;
import org.apache.lucene.analysis.standard.StandardTokenizer;
import org.apache.lucene.analysis.tokenattributes.CharTermAttribute;
import org.apache.lucene.analysis.tokenattributes.OffsetAttribute;
import org.apache.lucene .document.Document;
import org.apache.lucene .index.CorruptIndexException;
import org.apache.lucene .queryParser.ParseException;
import org.apache.lucene .queryParser.QueryParser;
import org.apache.lucene .search.IndexSearcher;
import org.apache.lucene .search.Query;
import org.apache.lucene .search.ScoreDoc;
import org.apache.lucene .search.TopDocs;
import org.apache.lucene .store.Directory;
import org.apache.lucene .store.FSDirectory;
import org.apache.lucene .util.Version;

/**
 *
 * @author DARK-NINE(NARAIN SAGAR)
 */

public class Searcher {
    IndexSearcher indexSearcher;
    QueryParser queryParser;
    Query query;
    public Searcher(String indexDirectoryPath) throws IOException{
        Directory indexDirectory;
        indexDirectory = FSDirectory.open(new File(indexDirectoryPath));
        indexSearcher = new IndexSearcher(indexDirectory);
        queryParser = new QueryParser(Version.LUCENE_36, 
                LuceneConstants.CONTENTS,
                new StandardAnalyzer(Version.LUCENE_36));
    }
    public TopDocs search( String searchQuery) throws IOException, ParseException{
        searchQuery = tokenizeStopStem(searchQuery); 
        query = queryParser.parse(searchQuery);
        return indexSearcher.search(query, LuceneConstants.MAX_SEARCH);
    }
    public TopDocs search(Query query) throws IOException, ParseException{
        return indexSearcher.search(query, LuceneConstants.MAX_SEARCH);
    }
    public Document getDocument(ScoreDoc scoreDoc) throws CorruptIndexException, IOException{
        return indexSearcher.doc(scoreDoc.doc);
    }
    public void close() throws IOException{
        indexSearcher.close();
    }
    public String tokenizeStopStem(String input) {
 
        TokenStream tokenStream = new StandardTokenizer(
                Version.LUCENE_36, new StringReader(input));
       // tokenStream = new StopFilter(Version.LUCENE_36, tokenStream, stopWords);
        tokenStream = new PorterStemFilter(tokenStream);
 
        StringBuilder sb = new StringBuilder();
        OffsetAttribute offsetAttribute = tokenStream.addAttribute(OffsetAttribute.class);
        CharTermAttribute charTermAttr = tokenStream.getAttribute(CharTermAttribute.class);
        try{
            while (tokenStream.incrementToken()) {
                if (sb.length() > 0) {
                    sb.append(" ");
                }
                sb.append(charTermAttr.toString());
            }
        }
        catch (IOException e){
            System.out.println(e.getMessage());
        }
        return sb.toString();
    }
}
