import { useState, useEffect } from 'react';
import { Prism as SyntaxHighlighter } from 'react-syntax-highlighter';
import { vscDarkPlus } from 'react-syntax-highlighter/dist/esm/styles/prism';
import ReactMarkdown from 'react-markdown';
import remarkGfm from 'remark-gfm';
import './index.css';

function App() {
  const [data, setData] = useState(null);
  const [selectedProblem, setSelectedProblem] = useState(null);
  const [expandedCategory, setExpandedCategory] = useState(null);
  const [searchQuery, setSearchQuery] = useState('');
  const [activeTab, setActiveTab] = useState('description');
  const [isSidebarCollapsed, setIsSidebarCollapsed] = useState(false);
  const [viewMode, setViewMode] = useState('split');

  useEffect(() => {
    fetch('./data.json')
      .then(res => res.json())
      .then(d => {
        setData(d);
        if (d.categories.length > 0) {
          setExpandedCategory(d.categories[0].name);
        }
        if (d.problems['130']) {
          setSelectedProblem(d.problems['130']);
          setActiveTab('description');
        }
      });
  }, []);

  if (!data) return <div className="loading">Loading Dashboard...</div>;

  return (
    <div className="app-container">
      <header className="app-header" style={{ display: 'grid', gridTemplateColumns: '1fr auto 1fr', alignItems: 'center' }}>
        <div className="header-left">
        </div>
        <div className="header-center" style={{ textAlign: 'center' }}>
          <h1 onClick={() => setSelectedProblem(null)} style={{ cursor: 'pointer', margin: 0 }}>
            My Neetcode solutions
          </h1>
        </div>
        <div className="header-right" style={{ display: 'flex', justifyContent: 'flex-end', gap: '1rem', alignItems: 'center' }}>
          <button 
            className="view-toggle-btn"
            onClick={() => {
              const newMode = viewMode === 'split' ? 'overview' : 'split';
              setViewMode(newMode);
              if (newMode === 'overview') setIsSidebarCollapsed(false);
            }}
            style={{
              background: 'rgba(255,255,255,0.1)',
              border: '1px solid rgba(255,255,255,0.2)',
              color: 'var(--text-main)',
              padding: '0.4rem 0.8rem',
              borderRadius: '6px',
              cursor: 'pointer',
              fontSize: '0.85rem'
            }}
          >
            {viewMode === 'split' ? 'Show Overview Table' : 'Show Tree View'}
          </button>
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
                      setActiveTab('description');
                      setSearchQuery('');
                      setViewMode('split');
                      setIsSidebarCollapsed(true);
                    }}>
                      <span className="status">{p.status_icon}</span>
                      <span>LC {p.id}: {p.title}</span>
                    </div>
                  ))}
              </div>
            )}
          </div>
        </div>
      </header>

      <div className="main-content">
        <main className={`content-panel ${viewMode === 'split' ? 'split-view-container' : ''} ${isSidebarCollapsed && viewMode === 'split' ? 'sidebar-collapsed' : ''}`}>
          <div className={`home-table-container ${viewMode === 'split' ? 'split-left' : 'full-width'} ${isSidebarCollapsed && viewMode === 'split' ? 'collapsed' : ''}`}>
            
            {viewMode === 'split' && (
              <button 
                className="sidebar-toggle-btn"
                onClick={() => setIsSidebarCollapsed(!isSidebarCollapsed)}
                title={isSidebarCollapsed ? "Expand Sidebar" : "Collapse Sidebar"}
              >
                {isSidebarCollapsed ? '》' : '《 Collapse Sidebar'}
              </button>
            )}

            <div className="sidebar-content">
              {viewMode === 'overview' && (
                <div className="overall-progress" style={{ marginBottom: '1.5rem', background: 'rgba(0,0,0,0.2)', padding: '1rem', borderRadius: '8px', border: '1px solid var(--border-color)' }}>
                  <div style={{ display: 'flex', justifyContent: 'space-between', marginBottom: '0.5rem' }}>
                    <span style={{ fontWeight: 'bold', color: 'var(--text-main)' }}>Overall Progress</span>
                    <span style={{ color: 'var(--text-muted)' }}>{Object.values(data.problems).filter(p => p.is_solved).length} / {Object.keys(data.problems).length} Solved</span>
                  </div>
                  <div className="cat-progress-bar" style={{ height: '8px' }}>
                    <div 
                      className="cat-progress-fill" 
                      style={{ width: `${(Object.values(data.problems).filter(p => p.is_solved).length / Object.keys(data.problems).length) * 100}%` }}
                    ></div>
                  </div>
                </div>
              )}

              {viewMode === 'overview' ? (
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
                          <div className="cat-progress-container">
                            <div className="cat-progress-text">{cat.problems.filter(id => data.problems[id].is_solved).length}/{cat.problems.length} Solved</div>
                            <div className="cat-progress-bar">
                              <div 
                                className="cat-progress-fill" 
                                style={{ width: `${(cat.problems.filter(id => data.problems[id].is_solved).length / cat.problems.length) * 100}%` }}
                              ></div>
                            </div>
                          </div>
                        </td>
                        <td className="problems-cell">
                          {cat.problems.slice().sort((a, b) => parseInt(a) - parseInt(b)).map(probId => {
                            const prob = data.problems[probId];
                            const diffClass = prob.difficulty ? prob.difficulty.toLowerCase() : 'medium';
                            return (
                              <div 
                                key={prob.id} 
                                className={`prob-badge ${prob.is_solved ? 'solved' : 'unsolved'} ${diffClass} ${selectedProblem && selectedProblem.id === prob.id ? 'active' : ''}`}
                                onClick={() => {
                                  setSelectedProblem(prob);
                                  setExpandedCategory(prob.category);
                                  setActiveTab('description');
                                  setViewMode('split');
                                  setIsSidebarCollapsed(true);
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
              ) : (
                <div className="category-accordion-list">
                  {data.categories.map(cat => {
                    const isExpanded = expandedCategory === cat.name;
                    return (
                      <div key={cat.name} className={`category-accordion-item ${isExpanded ? 'expanded' : ''}`}>
                        <div 
                          className="category-accordion-header"
                          onClick={() => setExpandedCategory(isExpanded ? null : cat.name)}
                          style={{
                            padding: '0.8rem 1rem',
                            cursor: 'pointer',
                            display: 'flex',
                            justifyContent: 'space-between',
                            alignItems: 'center',
                            background: isExpanded ? 'rgba(255,255,255,0.05)' : 'transparent',
                            borderBottom: '1px solid var(--border-color)',
                            transition: 'background 0.2s'
                          }}
                        >
                          <span style={{ fontWeight: '500', fontSize: '0.9rem' }}>{cat.name}</span>
                          <span style={{ fontSize: '0.8rem', color: 'var(--text-muted)' }}>
                            {cat.problems.filter(id => data.problems[id].is_solved).length}/{cat.problems.length}
                          </span>
                        </div>
                        {isExpanded && (
                          <div className="category-accordion-body" style={{ padding: '0.5rem' }}>
                            {cat.problems.slice().sort((a, b) => parseInt(a) - parseInt(b)).map(probId => {
                              const prob = data.problems[probId];
                              const diffClass = prob.difficulty ? prob.difficulty.toLowerCase() : 'medium';
                              const isActive = selectedProblem && selectedProblem.id === prob.id;
                              return (
                                <div 
                                  key={prob.id}
                                  className={`tree-prob-item ${prob.is_solved ? 'solved' : 'unsolved'} ${isActive ? 'active' : ''}`}
                                  onClick={() => {
                                    setSelectedProblem(prob);
                                    setActiveTab('description');
                                    setIsSidebarCollapsed(true);
                                  }}
                                  style={{
                                    padding: '0.5rem 0.8rem',
                                    margin: '0.2rem 0',
                                    borderRadius: '6px',
                                    cursor: 'pointer',
                                    display: 'flex',
                                    alignItems: 'center',
                                    gap: '0.5rem',
                                    background: isActive ? 'var(--accent-color)' : 'transparent',
                                    color: isActive ? '#fff' : 'var(--text-main)',
                                    fontSize: '0.85rem'
                                  }}
                                >
                                  <span style={{ fontSize: '1.2rem' }}>{prob.status_icon}</span>
                                  <span style={{ overflow: 'hidden', textOverflow: 'ellipsis', whiteSpace: 'nowrap' }}>
                                    {prob.id}. {prob.title}
                                  </span>
                                </div>
                              );
                            })}
                          </div>
                        )}
                      </div>
                    );
                  })}
                </div>
              )}
            </div>
          </div>

          {selectedProblem && (
            <div className="problem-details split-right">
              <div className="problem-header" style={{ position: 'relative', display: 'flex', justifyContent: 'center', flexDirection: 'column', alignItems: 'center' }}>
                <div style={{ color: 'var(--text-muted)', fontSize: '0.9rem', marginBottom: '0.25rem' }}>{selectedProblem.category}</div>
                <a 
                  href={`https://github.com/rajeshkumarblr/mylc/blob/main/${selectedProblem.local_path}`}
                  target="_blank" 
                  rel="noreferrer"
                  style={{ color: '#7dd3fc', fontSize: '1.25rem', fontWeight: 'bold', textDecoration: 'none' }}
                >
                  {selectedProblem.id}. {selectedProblem.title}
                </a>
                <a href={selectedProblem.lc_url} target="_blank" rel="noreferrer" className="btn-leetcode" style={{ position: 'absolute', right: 0, top: '50%', transform: 'translateY(-50%)' }}>Solve on LeetCode</a>
              </div>

              <div className="tab-nav">
                <button 
                  className={`tab-btn ${activeTab === 'description' ? 'active' : ''}`}
                  onClick={() => setActiveTab('description')}
                >Description</button>
                {selectedProblem.approach && (
                  <button 
                    className={`tab-btn ${activeTab === 'approach' ? 'active' : ''}`}
                    onClick={() => setActiveTab('approach')}
                  >Solution Approach</button>
                )}
                <button 
                  className={`tab-btn ${activeTab === 'video' ? 'active' : ''}`}
                  onClick={() => setActiveTab('video')}
                >Explanation Video</button>
                <button 
                  className={`tab-btn ${activeTab === 'solution' ? 'active' : ''}`}
                  onClick={() => setActiveTab('solution')}
                >Solution</button>
              </div>

              <div className="tab-content">
                {activeTab === 'approach' && selectedProblem.approach && (
                  <div className="approach-section" style={{ lineHeight: '1.6', color: 'var(--text-main)', fontSize: '0.95rem' }}>
                    <ReactMarkdown remarkPlugins={[remarkGfm]}>{selectedProblem.approach}</ReactMarkdown>
                  </div>
                )}
                
                {activeTab === 'description' && (
                  <div className="description-section">
                    <h3>Problem Description</h3>
                    <div className="description-content lc-html-content">
                      {selectedProblem.description_html ? (
                        <div dangerouslySetInnerHTML={{ __html: selectedProblem.description_html }} />
                      ) : selectedProblem.description ? selectedProblem.description.split('\n').map((line, i) => {
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

