import { useState, useEffect } from 'react';
import { Prism as SyntaxHighlighter } from 'react-syntax-highlighter';
import { vscDarkPlus } from 'react-syntax-highlighter/dist/esm/styles/prism';
import ReactMarkdown from 'react-markdown';
import './index.css';

function App() {
  const [data, setData] = useState(null);
  const [selectedProblem, setSelectedProblem] = useState(null);
  const [expandedCategory, setExpandedCategory] = useState(null);
  const [searchQuery, setSearchQuery] = useState('');
  const [activeTab, setActiveTab] = useState('description');

  useEffect(() => {
    fetch('./data.json')
      .then(res => res.json())
      .then(d => {
        setData(d);
        if (d.categories.length > 0) {
          setExpandedCategory(d.categories[0].name);
        }
      });
  }, []);

  if (!data) return <div className="loading">Loading Dashboard...</div>;

  return (
    <div className="app-container">
      <header className="app-header">
        <div className="header-left">
          <h1 onClick={() => setSelectedProblem(null)} style={{ cursor: 'pointer' }}>
            Neetcode 150 solutions
          </h1>
        </div>
        <div className="search-container">
          <input 
            type="text" 
            className="search-input" 
            placeholder="Search LC ID or Title..." 
            value={searchQuery}
            onChange={(e) => setSearchQuery(e.target.value)}
          />
          {searchQuery && (
            <div className="search-results">
              {Object.values(data.problems)
                .filter(p => p.id.includes(searchQuery) || p.title.toLowerCase().includes(searchQuery.toLowerCase()))
                .slice(0, 10)
                .map(p => (
                  <div key={p.id} className="search-result-item" onClick={() => {
                    setSelectedProblem(p);
                    setExpandedCategory(p.category);
                    setActiveTab(p.approach ? 'approach' : 'description');
                    setSearchQuery('');
                  }}>
                    <span className="status">{p.status_icon}</span>
                    <span>LC {p.id}: {p.title}</span>
                  </div>
                ))}
            </div>
          )}
        </div>
        <div className="stats">
          <span>{Object.values(data.problems).filter(p => p.is_solved).length} / {Object.keys(data.problems).length} Solved</span>
        </div>
      </header>

      <div className="main-content">
        <main className={`content-panel split-view-container`}>
          <div className={`home-table-container split-left`}>
            <table className="home-table">
                <thead>
                  <tr>
                    <th style={{ width: '25%' }}>Category</th>
                    <th style={{ width: '75%' }}>Problems</th>
                  </tr>
                </thead>
                <tbody>
                  {data.categories.map(cat => (
                    <tr key={cat.name}>
                      <td className="category-cell">
                        <span className="cat-name">{cat.name}</span>
                        <div className="cat-stats">({cat.problems.filter(id => data.problems[id].is_solved).length}/{cat.problems.length} Solved)</div>
                      </td>
                      <td className="problems-cell">
                        {cat.problems.map(probId => {
                          const prob = data.problems[probId];
                          const diffClass = prob.difficulty ? prob.difficulty.toLowerCase() : 'medium';
                          return (
                            <div 
                              key={prob.id} 
                              className={`prob-badge ${prob.is_solved ? 'solved' : 'unsolved'}`}
                              onClick={() => {
                                setSelectedProblem(prob);
                                setExpandedCategory(prob.category);
                                setActiveTab(prob.approach ? 'approach' : 'description');
                              }}
                            >
                              <span className="prob-id">{prob.id}</span>
                              <div className="tooltip-card">
                                <div className="tooltip-header">
                                  <strong>LC {prob.id}: {prob.title}</strong>
                                  <span className={`diff-tag ${diffClass}`}>{prob.difficulty || 'Medium'}</span>
                                </div>
                                <div className="tooltip-status">
                                  Status: {prob.is_solved ? <span style={{color: '#4ade80'}}>Solved 🟢</span> : <span style={{color: '#94a3b8'}}>Unsolved ⚪</span>}
                                </div>
                                <p className="tooltip-desc">{prob.description ? prob.description.substring(0, 120) + '...' : 'No description available.'}</p>
                              </div>
                            </div>
                          );
                        })}
                      </td>
                    </tr>
                  ))}
                </tbody>
              </table>
          </div>

          {selectedProblem && (
            <div className="problem-details split-right">
              <div className="problem-header">
                <h2>LC {selectedProblem.id}: {selectedProblem.title}</h2>
                <a href={selectedProblem.lc_url} target="_blank" rel="noreferrer" className="btn-leetcode">Solve on LeetCode</a>
              </div>

              <div className="tab-nav">
                {selectedProblem.approach && (
                  <button 
                    className={`tab-btn ${activeTab === 'approach' ? 'active' : ''}`}
                    onClick={() => setActiveTab('approach')}
                  >Approach</button>
                )}
                <button 
                  className={`tab-btn ${activeTab === 'description' ? 'active' : ''}`}
                  onClick={() => setActiveTab('description')}
                >Description</button>
                <button 
                  className={`tab-btn ${activeTab === 'solution' ? 'active' : ''}`}
                  onClick={() => setActiveTab('solution')}
                >Solution</button>
                <button 
                  className={`tab-btn ${activeTab === 'video' ? 'active' : ''}`}
                  onClick={() => setActiveTab('video')}
                >Video</button>
              </div>

              <div className="tab-content">
                {activeTab === 'approach' && selectedProblem.approach && (
                  <div className="approach-section" style={{ lineHeight: '1.6', color: 'var(--text-main)', fontSize: '0.95rem' }}>
                    <ReactMarkdown>{selectedProblem.approach}</ReactMarkdown>
                  </div>
                )}
                
                {activeTab === 'description' && (
                  <div className="description-section">
                    <h3>Problem Description</h3>
                    <div className="description-content">
                      {selectedProblem.description ? selectedProblem.description.split('\n').map((line, i) => {
                        const trimmedLine = line.trim();
                        if (!trimmedLine) return null;
                        
                        if (trimmedLine.startsWith('Example') || trimmedLine.startsWith('Constraints:')) {
                          return <h4 key={i} className="desc-heading">{trimmedLine}</h4>;
                        }
                        if (trimmedLine.startsWith('Input:') || trimmedLine.startsWith('Output:') || trimmedLine.startsWith('Explanation:')) {
                          const parts = trimmedLine.split(':');
                          return (
                            <div key={i} className="desc-io">
                              <strong>{parts[0]}:</strong>{parts.slice(1).join(':')}
                            </div>
                          );
                        }
                        if (trimmedLine.startsWith('- ') || trimmedLine.startsWith('1 <= ') || trimmedLine.startsWith('0 <=')) {
                           return <li key={i} className="desc-list-item">{trimmedLine}</li>;
                        }
                        return <p key={i}>{trimmedLine}</p>;
                      }) : <p>No description available.</p>}
                    </div>
                  </div>
                )}
                
                {activeTab === 'video' && (
                  <div className="video-section">
                    {selectedProblem.video_url ? (
                      <div className="video-container">
                        <iframe 
                          src={selectedProblem.video_url} 
                          title="YouTube video player" 
                          allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" 
                          allowFullScreen
                        ></iframe>
                      </div>
                    ) : (
                      <div className="no-video">Video not available.</div>
                    )}
                  </div>
                )}

                {activeTab === 'solution' && (
                  <div className="code-section">
                    {selectedProblem.code ? (
                      <SyntaxHighlighter 
                        language="cpp" 
                        style={vscDarkPlus} 
                        customStyle={{
                          background: 'rgba(0, 0, 0, 0.4)',
                          padding: '1.5rem',
                          borderRadius: '12px',
                          border: '1px solid var(--border-color)',
                          fontSize: '0.9rem',
                          fontFamily: "'Fira Code', monospace",
                          margin: 0
                        }}
                      >
                        {selectedProblem.code}
                      </SyntaxHighlighter>
                    ) : (
                      <div className="no-code">Code not yet written.</div>
                    )}
                  </div>
                )}
              </div>
            </div>
          )}
        </main>
      </div>
    </div>
  );
}

export default App;

